/*
 *  score_readxml.cpp
 *
 * Copyright (C) 2010-2022 Andrea Agostini and Daniele Ghisi
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License
 * as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.
 * If not, see <https://www.gnu.org/licenses/>.
 *
 */

#include "score_files.h"
#include "libraries/mxml/mxml.h"
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

#ifdef WIN_VERSION
#include <typeinfo>
#endif

#define CONST_DYNAMICS_TEXT_ALLOC_SIZE 2048

#ifdef WIN_VERSION
#define strtok_r strtok_s
#endif 
//#define SCORE_READXML_POSTLL

t_rational xml_name_and_dots_to_value(const char *chordtype, long dots);

mxml_type_t xml_load_cb(mxml_node_t *node);

const char *bach_xml_acc2name(t_rational acc, long *mc_alter);


const char* const xml_accepted_dynamics[] = { "p", "pp", "ppp", "pppp", "ppppp", "pppppp", "f", "ff", "fff", "ffff", "fffff", "ffffff", "mp", "mf", "sf", "sfp", "sfpp", "fp", "rf", "rfz", "sfz", "sffz", "fz", "0", "n"};
constexpr long num_xml_accepted_dynamics = sizeof(xml_accepted_dynamics)/sizeof(xml_accepted_dynamics[0]);




class score {
    
private:
    
    class voice;
    class part;
    
    
    
    //////////////////////////
    //
    //  timedThing
    //
    //////////////////////////
    
    template <typename OwnerType>
    class timedThing {
    protected:
    public:

        OwnerType* owner;
        t_rational timePos; // absolute
        t_rational offset; // relative to the reference item

        double relativeX;
        
        timedThing(OwnerType* v, t_rational timePos, double relativeX = 0) : owner(v), timePos(timePos), offset(0), relativeX(relativeX) {
            if (timePos == t_rational(0) && relativeX < 0)
                relativeX = 0;
        };
        
        virtual ~timedThing() { }
        
        static bool cmp(const timedThing* a, const timedThing* b);
    };
    
    

    //////////////////////////
    //
    //  timedThingContainer
    //
    //////////////////////////
    
    class timedThingContainer {
    public:
        template <typename OwnerType>
        class timedThingVector {
            using timedThingPtrVector = std::vector<timedThing<OwnerType> *>;
            
        public:
            timedThingPtrVector stuff;
            
            timedThingVector() = default;
            
            virtual ~timedThingVector() { }
            
            void sort() {
                std::stable_sort(stuff.begin(), stuff.end(), timedThing<OwnerType>::cmp);
            }
            
            void insert(timedThing<OwnerType> *t) { stuff.push_back(t); }
            
            void deleteContents() {
                for (auto i : stuff)
                    delete i;
            }

        };
        
        timedThingVector<voice> chordBased;
        timedThingVector<part> minfoBased;
        
    public:
        void sort() {
            chordBased.sort();
            minfoBased.sort();
        }
        
        void insertDirectionFromXML(mxml_node_t *directionXML, t_rational global_position, long divisions, long* velocity, part* partOwner = nullptr);
        
        void insert(timedThing<voice> *t) { chordBased.insert(t); }
        void insert(timedThing<part> *t) { minfoBased.insert(t); }
        
        void remove(timedThing<part> *t) {
            for (auto i = minfoBased.stuff.begin();
                 i != minfoBased.stuff.end();
                 i++) {
                if (*i == t) {
                    minfoBased.stuff.erase(i);
                    break;
                }
            }
        }
    };
    
    
    class note;
    
    //////////////////////////
    //
    //  slotTimedThing
    //
    //////////////////////////
    
    class slotTimedThing : public timedThing<voice> {
    public:
        note* refNote;
        slotTimedThing(t_rational timePos, double relativeX = 0) : timedThing(nullptr, timePos, relativeX), refNote(nullptr) { }
        
        void setOffset(bool singleSlotForTiedNotes = true);
        
    };
    
    
    
    
    //////////////////////////
    //
    //  dynamics
    //
    //////////////////////////
    
    class dynamics : public slotTimedThing {
    public:
        std::string dyn;
        enum types { standard, wedge, wedgeEnd } type;
        
        dynamics(std::string dyn, types type, t_rational timePos, double relativeX = 0) : slotTimedThing(timePos, relativeX), dyn(dyn), type(type) { }
        
        dynamics(const char * dyn, types type, t_rational timePos, double relativeX = 0) : slotTimedThing(timePos, relativeX), dyn(dyn), type(type) { }
        
    };
    
    
    //////////////////////////
    //
    //  words
    //
    //////////////////////////
    
    class words : public slotTimedThing {
    public:
        std::string txt;
        words(const char* txt, t_rational timePos, double relativeX = 0) : slotTimedThing(timePos, relativeX), txt(txt) { }
    };
    
    
    class level;
    
    
    
    //////////////////////////
    //
    //  levelChild
    //
    //////////////////////////
    
    class levelChild {
    public:
        level *parent;
        virtual ~levelChild() { }
        virtual t_llll* getllll() = 0;
    
    protected:
        levelChild() : parent(nullptr) { }
        levelChild(level *parent) : parent(parent) { }
    };
    
    class chord;
    
    
    
    //////////////////////////
    //
    //  thingWithSlots
    //
    //////////////////////////
    
    class thingWithSlots {
    public:
        std::vector<t_llll *> slots;
        thingWithSlots() : slots(CONST_MAX_SLOTS, nullptr) { }
        
        virtual ~thingWithSlots() {
            for (t_llll *s : slots)
                llll_free(s);
        }
        
        void setSlot(int n, t_llll *slotll) {
            if (n >= 1 && n <= CONST_MAX_SLOTS)
                slots[n - 1] = slotll;
        }
        
        t_llll *getSlotsllll() {
            t_llll* ll = llll_get();
            for (int n = 0 ; n < CONST_MAX_SLOTS; n++) {
                if (slots[n]) {
                    t_llll* slotll = llll_get();
                    llll_appendlong(slotll, n+1);
                    llll_chain(slotll, llll_clone(slots[n]));
                    llll_appendllll(ll, slotll);
                }
            }
            llll_prependsym(ll, _llllobj_sym_slots);
            return ll;
        }
    };
    
    class dynamicsllData {
    public:
        t_llll *dyn;
        t_rational timePos;
        t_llll *value;
        t_llllelem *wedge;
        
        dynamicsllData() :
            dyn(nullptr),
            timePos(t_rational(-1, 1)),
            value(nullptr),
            wedge(nullptr)
        { }
    };
    
    //////////////////////////
    //
    //  note
    //
    //////////////////////////
    
    class note : public thingWithSlots {
    public:
        chord *owner;
        t_pitch pitch;
        int     velocity;
        bool    tied;
        note* tiedFrom;
        note* tiedTo;
        note* tieStart;
        note* tieEnd;
        t_rational prevDuration;
        std::vector<dynamics*> dynamicsSlotContents;
        std::vector<words*> directionSlotContents;

        note(chord* owner) :
            owner(owner),
            pitch(t_pitch::C0),
            velocity(-1),
            tied(false),
            tiedFrom(nullptr),
            tiedTo(nullptr),
            tieStart(this),
            tieEnd(this),
            prevDuration(0)
        { }
        
        note(chord* owner, t_pitch pitch, int velocity, bool tied) :
            owner(owner),
            pitch(pitch),
            velocity(velocity),
            tied(tied),
            tiedFrom(nullptr),
            tiedTo(nullptr),
            tieStart(this),
            tieEnd(this),
            prevDuration(0)
        { }
        
        static bool cmp(note* a, note* b) {
            return a->pitch < b->pitch;
        }
        
        t_llll* getllll() {
            
            t_llll* ll = llll_get();
            
            llll_appendpitch(ll, pitch);
            llll_appendlong(ll, velocity);
            llll_appendlong(ll, tied ? 1 : 0);
            

            t_llll *slotsll = getSlotsllll();

            score* theScore = owner->owner->owner->owner;
            
            
            if (long directionsSlot = theScore->directionsSlot; directionsSlot > 0) {
                // directions, the easy one
                t_llll *directionsll = llll_get();
                for (auto w : directionSlotContents) {
                    const char* txt = w->txt.c_str();
                    llll_appendsym(directionsll, gensym(txt));
                }
                
                if (directionsll->l_size) {
                    llll_prependlong(directionsll, directionsSlot);
                    llll_appendllll(slotsll, directionsll);
                } else {
                    llll_free(directionsll);
                }
            }
            
            if (long dynamicsSlot = theScore->dynamicsSlot; dynamicsSlot > 0) {
                // dynamics, the tough one
                t_llll *dynamicsll = llll_get();
                t_llll *dyn = nullptr;
                t_llll *value = nullptr;
                t_llllelem *wedge = nullptr;
                t_rational timePos = {-1, 1};
                
                for (auto d : dynamicsSlotContents) {
                    //t_rational offset = d->offset;
                    //t_rational timePos = d->timePos;
                    t_symbol* sym = gensym(d->dyn.c_str());
                    
                    switch(d->type) {
                            
                        case dynamics::types::standard :
                        case dynamics::types::wedgeEnd : {
                            if (d->timePos != timePos) {
                                dyn = llll_get();
                                llll_appenddouble(dyn, d->offset);
                                value = llll_get();
                                llll_appendsym(value, sym);
                                llll_appendllll(dyn, value);
                                wedge = llll_appendsym(dyn, gensym("="));
                                llll_appendllll(dynamicsll, dyn);
                                timePos = d->timePos;
                            } else {
                                if (hatom_getsym(&value->l_tail->l_hatom) == gensym("|")) {
                                    hatom_change_to_sym(&value->l_tail->l_hatom, sym);
                                } else {
                                    llll_appendsym(value, sym);
                                }
                            }
                            break;
                        }
                            
                        case dynamics::types::wedge : {
                            if (d->timePos != timePos) {
                                dyn = llll_get();
                                llll_appenddouble(dyn, d->offset);
                                value = llll_get();
                                llll_appendllll(dyn, value);
                                wedge = llll_appendsym(dyn, sym);
                                llll_appendllll(dynamicsll, dyn);
                                timePos = d->timePos;
                            } else {
                                hatom_change_to_sym(&wedge->l_hatom, sym);
                            }
                            break;
                        }
                    }
                }
                
                if (dynamicsll->l_size > 0) {
                    llll_prependlong(dynamicsll, dynamicsSlot);
                    llll_appendllll(slotsll, dynamicsll);
                } else {
                    llll_free(dynamicsll);
                }
            }
            
            if (slotsll->l_size > 1) {
                llll_appendllll(ll, slotsll);
            } else {
                llll_free(slotsll);
            }
            return ll;
        }
    };
    
    
    
    //////////////////////////
    //
    //  chord
    //
    //////////////////////////
    
    class chord : public timedThing<voice>, public levelChild, public thingWithSlots {
    public:
        //chordParent *parent;
        t_rational duration;
        bool grace;
        std::vector<note *> notes;
        note* currentNote;
        int ties;
        bool rest; // if a chord is a rest it will anyway have a dummy note
        
        chord(voice *owner, t_rational duration, bool grace = false);
        
        chord(voice *owner, bool grace = false);
        
        void addNote(note* n) {
            notes.push_back(n);
            currentNote = n;
        }
        
        void setNoteSlot(int n, t_llll *slotll) {
            currentNote->setSlot(n, slotll);
        }

        
        virtual ~chord() {
            for (auto n : notes)
                delete n;
        }
        
        note* findNoteForSlots(bool singleSlotForTiedNotes = true) {
            note* chosen = nullptr;
            for (note* n : notes) {
                if (!n->tiedFrom) {
                    chosen = n;
                    break;
                } else if (!chosen || chosen->prevDuration < n->prevDuration)
                    chosen = n;
            }
            return chosen && singleSlotForTiedNotes ? chosen->tieStart : chosen;
        }
        
        t_llll* getllll() {
            t_llll *ll = llll_get();
            llll_appendrat(ll, duration);
            
            if (!rest)
                for (note* n : notes) {
                    llll_appendllll(ll, n->getllll());
                }
            
            t_llll* slotsll = getSlotsllll();
            if (slotsll->l_size > 1)
                llll_appendllll(ll, slotsll);
            else
                llll_free(slotsll);
            
            return ll;
        }
    };
    
    
    
    
    //////////////////////////
    //
    //  level
    //
    //////////////////////////
    
    class level : public levelChild {
    public:
        std::vector<levelChild *> children;
        using levelChild::levelChild;
        
        level* addChildLevel() {
            level* l = new level(this);
            children.push_back(l);
            return l;
        }
        
        void addChord(chord* c) {
            children.push_back(c);
        }
        
        t_llll* getllll() {
            t_llll* ll = llll_get();
            for (auto c : children) {
                llll_appendllll(ll, c->getllll());
            }
            return ll;
        }
        
        virtual ~level() {
            for (auto c : children)
                if (typeid(c) == typeid(level))
                    delete c; // chords are deleted by timedThingContainer
        }
    };

    class measureinfo;
    
    
    
    
    //////////////////////////
    //
    //  tempo
    //
    //////////////////////////
    
    class tempo : public timedThing<part> {
    public:
        t_rational figure;
        double bpm;
        measureinfo* refMinfo;
        
        tempo(part* owner, t_rational timePos, double relativeX, t_rational figure, double bpm) :
            timedThing(owner, timePos, relativeX),
            figure(figure),
            bpm(bpm),
            refMinfo(nullptr)
        { }
        
        void setOffset();
        
        t_llll *getllll() {
            t_llll *ll = llll_get();
            llll_appendrat(ll, figure);
            llll_appenddouble(ll, bpm);
            llll_appendrat(ll, offset);
            return ll;
        }

    };
    
    
    
    
    
    
    
    //////////////////////////
    //
    //  timeSignature
    //
    //////////////////////////
    
    class timeSignature {
    public:
        std::vector<int> num;
        int den;
        bool valid;
        
        
        void addNumElem(int e) {
            num.push_back(e);
        }
        
        t_rational getDuration() {
            int durNum = std::accumulate(num.begin(), num.end(), 0);
            return t_rational(durNum, den);
        }
        
        timeSignature() : den(0), valid(false) { }
        
        
        timeSignature(int singleNum, int den) : den(den), valid(true) {
            num.push_back(singleNum);
        }
        
        t_llll *getllll() {
            t_llll *ll = llll_get();
            if (num.size() == 1) {
                llll_appendlong(ll, num[0]);
            } else {
                t_llll *numll = llll_get();
                for (int n : num) {
                    llll_appendlong(numll, n);
                }
                llll_appendllll(ll, numll);
            }
            llll_appendlong(ll, den);
            return ll;
        }
        
        void adjust(t_rational dur) {
            
            if (valid)
                return;
            
            num.clear();
            long d = dur.den();
            if (log2(double(d)) == perfect_log2(d)) {
                if (d <= 4) {
                    num.push_back(dur.num() * 4 / d);
                    den = 4;
                } else {
                    num.push_back(dur.num());
                    den = d;
                }
            } else {
                long q = (long) ceil(double(dur) * 4);
                num.push_back(q);
                den = 4;
            }
        }
        
        timeSignature(mxml_node_t* attributesXML, t_score *x) {
            
            valid = false;
            den = 1;

            if (!attributesXML)
                return;
            
            // time signature
            mxml_node_t *timeXML = mxmlFindElement(attributesXML, attributesXML, "time", NULL, NULL, MXML_DESCEND_FIRST);
            mxml_node_t *beatsXML, *beat_typeXML;
            //= mxmlFindElement(timeXML, timeXML, "beats", NULL, NULL, MXML_DESCEND_FIRST);
            //mxml_node_t *beat_typeXML = mxmlFindElement(timeXML, timeXML, "beat-type", NULL, NULL, MXML_DESCEND_FIRST);
            // first find lcm
            for (beat_typeXML = mxmlFindElement(timeXML, timeXML, "beat-type", NULL, NULL, MXML_DESCEND_FIRST);
                 beat_typeXML;
                 beat_typeXML = mxmlFindElement(beat_typeXML, timeXML, "beat-type", NULL, NULL, MXML_NO_DESCEND)) {
                if (mxmlFindElement(beat_typeXML, timeXML, "interchangeable", NULL, NULL, MXML_NO_DESCEND))
                    break;
                den = lcm(den, mxmlGetInteger(beat_typeXML));
            }
            long beat_type = 0;
            if (den == 0) { // which means that one of the beat_types is 0 - thus we prevent division by 0 below
                object_error((t_object *) x, "Bad time signature");
            } else {
                for (beatsXML = mxmlFindElement(timeXML, timeXML, "beats", NULL, NULL, MXML_DESCEND_FIRST);
                     beatsXML;
                     beatsXML = mxmlFindElement(beatsXML, timeXML, "beats", NULL, NULL, MXML_NO_DESCEND)) {
                    if (mxmlFindElement(beatsXML, timeXML, "interchangeable", NULL, NULL, MXML_NO_DESCEND))
                        break;
                    beat_typeXML = mxmlFindElement(beatsXML, timeXML, "beat-type", NULL, NULL, MXML_NO_DESCEND);
                    if (!beat_typeXML)
                        break;
                    beat_type = mxmlGetInteger(beat_typeXML);
                    long d = den / beat_type;
                    
                    char *rest = (char *)bach_newptr(2048);
                    const char *beatstxt = mxmlGetOpaque(beatsXML);
                    strncpy_zero(rest, beatstxt, 2048);
                    char *tok;
                    while ((tok = strtok_r(rest, "+", &rest))) {
                        long beats = strtol(tok, nullptr, 10);
                        num.push_back(beats * d);
                        valid = true;
                    }
                }
            }
        }
        
        bool operator==(const timeSignature& b) const {
            return num == b.num && den == b.den;
        }
        
        bool operator!=(const timeSignature& b) const {
            return !(*this == b);
        }
        
    };
    
    
    
    //////////////////////////
    //
    //  measureinfo
    //
    //////////////////////////
    
    class measureinfo : public timedThing<part> {
    public:
        timeSignature timeSig;
        std::vector<tempo*> tempi;
        t_llll *barline;
        measureinfo* prev;
        t_rational fullDuration;
        int number;
        t_llll *ll;

        measureinfo(part *owner, t_rational pos, measureinfo* prev):
            timedThing(owner, pos),
            barline(nullptr),
            prev(prev),
            ll(nullptr)
        {
            if (!prev)
                number = 0;
            else
                number = prev->number + 1;
        }

        void setTimeSignature(mxml_node_t* attributesXML, t_score *x) {
            timeSignature newTimeSig = timeSignature(attributesXML, x);
            if (newTimeSig.valid)
                timeSig = newTimeSig;
            else if (!prev) {
                timeSig = timeSignature(0, 4);
                timeSig.valid = false;
                //object_error((t_object *) x, "Missing time signature");
            } else {
                timeSignature prevTimeSig = prev->timeSig;
                if (prevTimeSig.valid)
                    timeSig = prevTimeSig;
                else {
                    timeSig = timeSignature(0, 4);
                    timeSig.valid = false;
                }
            }
            fullDuration = timeSig.getDuration();
        }
        
        timeSignature *getTimeSignature() {
            return &timeSig;
        }
        
        // the llll ownership is kept.
        t_llll *getllll() {
            if (!ll) {
                ll = llll_get();
                llll_appendllll(ll, timeSig.getllll());
                t_llll *tempill = llll_get();
                for (auto t : tempi) {
                    llll_appendllll(tempill, t->getllll());
                }
                if (tempill->l_size > 0)
                    llll_appendllll(ll, tempill);
                else
                    llll_free(tempill);
            }
            return ll;
        }
        
        ~measureinfo() {
            llll_free(ll);
        }

    };
    
    
    
    //////////////////////////
    //
    //  measure
    //
    //////////////////////////
    
    class measure {
    public:
        //const voice *owner;
        //int divisions;
        int number;
        level firstLevel;
        level* currentLevel;
        t_rational usedDuration;
        voice *owner;
        
        measure(measure* prev, voice* owner) :
            currentLevel(&firstLevel),
            usedDuration(t_rational(0)),
            owner(owner)
        {
            if (prev)
                number = prev->number + 1;
            else
                number = 0;
        }
        
        measureinfo* getMeasureInfo() {
            return owner->owner->measureinfos[number];
        }
        
        void addChord(chord *c) {
            currentLevel->addChord(c);
            usedDuration += c->duration;
        }

        chord* finalize(t_score *x) {
            chord* r = nullptr;
            t_rational fullDur = getMeasureInfo()->fullDuration;
            if (usedDuration < fullDur) {
                r = new chord(owner, fullDur - usedDuration, false);
                addChord(r);
            } else if (usedDuration > fullDur) {
                object_warn((t_object *) x, "Overfull measure");
            }
            return r;
        }
        
        level* pushLevel() {
            currentLevel = currentLevel->addChildLevel();
            return currentLevel;
        }
        
        t_llll *getllll() {
            t_llll *ll = llll_get();
            llll_appendllll(ll, llll_clone(getMeasureInfo()->getllll()));
            if (number == 0) {
                t_rational fullDur = getMeasureInfo()->fullDuration;
                t_rational missing = fullDur - usedDuration;
                if (missing > 0) {
                    auto l = level();
                    auto c = chord(owner, missing);
                    c.rest = true;
                    l.addChord(&c);
                    llll_chain(ll, l.getllll());
                }
            }
            llll_chain(ll, firstLevel.getllll());
            return ll;
        }
        
        virtual ~measure() {
            
        }
    };
    
    
    
    //////////////////////////
    //
    //  voice
    //
    //////////////////////////
    
    class voice {
    public:
        part *owner;
        int num;
        std::vector<measure *> measures;
        t_symbol *clef;
        t_symbol *key;
        std::string name;
        measure *currentMeasure;
        chord* currentChord;
        chord* prevChord;
        dynamicsllData lastDynamicsData;
        
        voice(part *owner) :
            owner(owner),
            num(0),
            clef(nullptr),
            key(nullptr),
            currentMeasure(nullptr),
            currentChord(nullptr),
            prevChord(nullptr)
        { }
        
        voice(const voice* obj, const bool dummy) :
            owner(obj->owner),
            num(obj->num + 1),
            clef(obj->clef),
            key(obj->key),
            name(obj->name),
            currentChord(nullptr),
            prevChord(nullptr)
        {
            currentMeasure = nullptr;
            for (auto m : obj->measures) {
                currentMeasure = new measure(currentMeasure, this);
                measures.push_back(currentMeasure);
            }
        }
        
        void addMeasure(measureinfo *info) {
            currentMeasure = new measure(currentMeasure, this);
            measures.push_back(currentMeasure);
        }
        
        chord* finalizeMeasure(t_score *x) {
            chord *r = currentMeasure->finalize(x);
            if (r) {
                prevChord = currentChord;
                currentChord = r;
            }
            return r;
        }

        void addChord(chord* c) {
            currentChord = c;
            currentMeasure->addChord(c);
        }
        
        void setChordDuration(t_rational dur) {
            if (!currentChord->grace) {
                currentChord->duration = dur;
                currentMeasure->usedDuration += dur;
            }
        }
        
        void adjustTies() {
            if (!prevChord || prevChord->ties == 0)
                return;
            
            std::vector<note*>::iterator currentNoteIterator = currentChord->notes.begin();
            for (note* prevNote : prevChord->notes) {
                if (prevNote->tied) {
                    for ( ;
                         currentNoteIterator != currentChord->notes.end() && (*currentNoteIterator)->pitch < prevNote->pitch ;
                         currentNoteIterator++)
                        ;
                    
                    if (currentNoteIterator == currentChord->notes.end()) {
                        object_error((t_object *) owner->owner->obj, "Tie mismatch");
                        break;
                    }
                    
                    if ((*currentNoteIterator)->pitch == prevNote->pitch) {
                        prevNote->tiedTo = *currentNoteIterator;
                        (*currentNoteIterator)->tiedFrom = prevNote;
                        
                        (*currentNoteIterator)->tieStart = prevNote->tieStart;
                        for (note* n = prevNote->tieStart;
                             n != *currentNoteIterator;
                             n = n->tiedTo)
                            n->tieEnd = *currentNoteIterator;
                        
                        if (!prevChord->grace)
                            (*currentNoteIterator)->prevDuration += prevChord->duration;
                        currentNoteIterator++;
                    } else {
                        object_error((t_object *) owner->owner->obj, "Tie mismatch");
                        prevNote->tied = false;
                        prevChord->ties--;
                    }
                }
            }
        }
        
        
        level* pushLevel() {
            return currentMeasure->pushLevel();
        }
        
        t_llll* getllll() {
            t_llll *ll = llll_get();
            for (auto m : measures) {
                llll_appendllll(ll, m->getllll());
            }
            return ll;
        }
        
        
        
        virtual ~voice() {
            for (auto m : measures)
                delete m;
        }
        
    };
    

    //////////////////////////
    //
    //  part
    //
    //////////////////////////
    
    class part {
        //friend class score;
    public:
        score* owner;
        std::vector<voice *> voices;
        std::vector<measureinfo *> measureinfos;
        bool hasMeasureInfo;
        
        inline int getNumVoices() { return voices.size(); }
        
        int number;
        voice* currentVoice;
        int currentVoiceNum;
        
        t_rational globalPosition;
        t_rational positionInMeasure;
        
        timedThingContainer theTimedThings;
        
        std::vector<t_llll*> infolls;
        
        part(score* owner, int n) : owner(owner)
        {
            voice* v = new voice(this);
            voices.push_back(v);
            number = n;
            currentVoice = v;
            currentVoiceNum = 0;
            globalPosition = t_rational(0);
            positionInMeasure = t_rational(0);
            hasMeasureInfo = true;
        }
        
        int addVoice() {
            int n = getNumVoices();
            voices.push_back(new voice(voices[n-1], true));
            return n;
        }
        
        level* pushLevel() {
            return currentVoice->pushLevel();
        }
        
        void setClef(t_symbol *clef) {
            for (auto v : voices)
                v->clef = clef;
        }
        
        void setKey(t_symbol *key) {
            for (auto v : voices)
                v->key = key;
        }
        
        void setClef(const char *clef) { setClef(gensym(clef)); }
        void setKey(const char *key) { setClef(gensym(key)); }
        
        
        void insertDirectionFromXML(mxml_node_t *directionXML, long divisions, long* velocity) {
            theTimedThings.insertDirectionFromXML(directionXML, globalPosition, divisions, velocity);
        }
        
        
        measureinfo* createNewMeasure() {
            measureinfo* prev = measureinfos.size() > 0 ? measureinfos.back() : nullptr;
            measureinfo* curr = new measureinfo(this, globalPosition, prev);
            measureinfos.push_back(curr);
            theTimedThings.insert(curr);
            for (auto v : voices) {
                v->addMeasure(curr);
            }
            positionInMeasure = t_rational{0};
            return curr;
        }
        
        void finalizeMeasure(t_score *x) {
            voice* current = currentVoice;
            for (auto v : voices) {
                currentVoice = v;
                chord *c = v->finalizeMeasure(x);
                if (c)
                    finalizeChord();
            }
            currentVoice = current;
        }
        
        void setTimeSignature(mxml_node_t* attributesXML, t_score *x) {
            measureinfos.back()->setTimeSignature(attributesXML, x);
        }
        
        void adjustTimeSignatureIfNeeded() {
            measureinfo *minfo = measureinfos.back();
            timeSignature *ts = minfo->getTimeSignature();
            if (!ts->valid) {
                ts->adjust(positionInMeasure);
            }
        }
        
        void backup(t_rational r, t_score *x) {
            globalPosition -= r;
            positionInMeasure -= r;
            if (globalPosition < 0) {
                object_warn((t_object *) x, "<backup> tag wants to backup too far");
                globalPosition = positionInMeasure = t_rational(0);
            } else if (positionInMeasure < 0) {
                object_warn((t_object *) x, "<backup> tag wants to backup too far");
                positionInMeasure = t_rational(0);
            }
        }
        
        void addChord(t_rational dur, bool grace = false) {
            currentVoice->addChord(new chord{currentVoice, dur, grace});
            if (!grace) {
                globalPosition += dur;
                positionInMeasure += dur;
            }
        }
        
        void addChord(bool grace = false) {
            currentVoice->addChord(new chord{currentVoice, grace});
        }
        
        const note* addNote(t_pitch pitch, int velocity, bool tie) {
            chord* c = currentVoice->currentChord;
            if (!c) {
                object_warn(nullptr, "<chord> tag with no preceding note");
                return nullptr;
            }
            note *n = new note{c, pitch, velocity, tie};
            c->addNote(n);
            if (tie)
                c->ties++;
            return n;
        }
        
        void setNoteSlot(int n, t_llll *slotll) {
            chord* c = currentVoice->currentChord;
            if (c)
                c->setNoteSlot(n, slotll);
        }
        
        void setChordSlot(int n, t_llll *slotll) { currentVoice->currentChord->setSlot(n, slotll); }

        //void setChordParent(chordParent *p) { currentVoice->setChordParent(p); }
        
        level *getCurrentLevel() { return currentVoice->currentMeasure->currentLevel; }
        
        bool climbSafe() {
            level *current = currentVoice->currentMeasure->currentLevel;
            if (current->parent) {
                currentVoice->currentMeasure->currentLevel = current->parent;
                return true;
            } else {
                return false;
            }
        }
        
        void setChordDuration(t_rational dur) {
            currentVoice->setChordDuration(dur);
            globalPosition += dur;
            positionInMeasure += dur;
        }
        
        void setChordSlot(t_llll* slotll) {
        //    currentVoice->currentChord->slots = slotll;
        }
        
        void setBarline(t_llll* barlinell) {
            currentVoice->currentMeasure->getMeasureInfo()->barline = barlinell;
        }
        
        void setTimeSignature(timeSignature& timeSig) {
            currentVoice->currentMeasure->getMeasureInfo()->timeSig = timeSig;
        }
        
        void finalize(bool singleDyns, bool singleDirs) {

            theTimedThings.sort();
            
            std::vector<chord*> lastChords(getNumVoices(), nullptr);
            std::vector<chord*> lastChordsAndRests(getNumVoices(), nullptr);
            std::vector<dynamics*> lastDynamic(getNumVoices(), nullptr);
            
            for (auto thing : theTimedThings.chordBased.stuff) {
                if (chord *c = dynamic_cast<chord*>(thing)) {
                    int v = c->owner->num;
                    lastChordsAndRests[v] = c;
                    if (!c->rest)
                        lastChords[v] = c;
                    
                } else if (words *w = dynamic_cast<words*>(thing)) {
                    note* found = nullptr;
                    
                    for (chord* lc : lastChordsAndRests) {
                        if (!lc)
                            continue;
                        note* candidate = lc->findNoteForSlots(singleDirs);
                        if (!found ||
                            (!singleDirs && candidate->tieStart->owner->timePos > found->tieStart->owner->timePos)) {
                            found = candidate;
                        }
                    }
                    int v = found->owner->owner->num;
                    w->owner = voices[v];
                    w->refNote = found;
                    w->setOffset(singleDirs);
                    found->directionSlotContents.push_back(w);
                    
                } else if (dynamics *d = dynamic_cast<dynamics*>(thing)) {
                    
                    note *found = nullptr;
                    if (d->type == dynamics::types::wedgeEnd) {
                        for (auto d : lastDynamic) {
                            if (d && d->type == dynamics::types::wedge) {
                                int v = d->owner->num;
                                if (lastChords[v]) {
                                    found = lastChords[v]->findNoteForSlots(singleDyns);
                                    break;
                                }
                            }
                        }
                    }
                    
                    if (!found) {
                        for (chord* lc : lastChords) {
                            if (!lc)
                                continue;
                            note* candidate = lc->findNoteForSlots();
                            if (!found ||
                                (!singleDyns && candidate->tieStart->owner->timePos > found->tieStart->owner->timePos)) {
                                found = candidate;
                            }
                        }
                    }
                    
                    if (found) {
                        int v = found->owner->owner->num;
                        d->owner = voices[v];
                        d->refNote = found;
                        d->setOffset(singleDyns);
                        found->dynamicsSlotContents.push_back(d);
                        lastDynamic[v] = d;
                    }
                }
            }
            
            if (number == 0)
                hasMeasureInfo = true;
            else {
                part *prevPart = owner->parts[number - 1];
                hasMeasureInfo = false;
                
                for (auto thing : theTimedThings.minfoBased.stuff) {
                    if (measureinfo* mi = dynamic_cast<measureinfo*>(thing)) {
                        if (prevPart->measureinfos[mi->number]->timeSig != mi->timeSig) {
                            hasMeasureInfo = true;
                            break;
                        }
                    } else {
                        hasMeasureInfo = true;
                        break;
                    }
                }
                
                if (!hasMeasureInfo) {
                    theTimedThings.minfoBased.stuff.clear();
                    measureinfos = owner->parts[number - 1]->measureinfos;
                }
            }
            
            if (hasMeasureInfo) {
                measureinfo* lastInfo = nullptr;
                for (auto thing : theTimedThings.minfoBased.stuff) {
                    if (measureinfo* mi = dynamic_cast<measureinfo*>(thing)) {
                        lastInfo = mi;
                    } else if (tempo* t = dynamic_cast<tempo*>(thing)) {
                        t->refMinfo = lastInfo;
                        t->setOffset();
                        lastInfo->tempi.push_back(t);
                    }
                }
            }
        }
        
        
        bool finalizeChord() {
            chord *c = currentVoice->currentChord;
            if (!c)
                return false;
            if (c->notes.size() > 0) {
                c->rest = false;
                std::sort(c->notes.begin(), c->notes.end(), note::cmp);
                currentVoice->adjustTies();
            } else {
                c->rest = true;
                c->notes.push_back(new note(c));
            }
            
            theTimedThings.insert(c);
            
            currentVoice->prevChord = currentVoice->currentChord;
            currentVoice->currentChord = nullptr;
            return true;
        }
        
        bool updateCurrentVoice(mxml_node_t *itemXML) {
            bool switchToNewVoice = false;
            mxml_node_t *voiceXML = mxmlFindElement(itemXML, itemXML, "voice", NULL, NULL, MXML_DESCEND_FIRST);
            
            if (voiceXML) {
                int newvoice = mxmlGetInteger(voiceXML) - 1;
                if (newvoice != currentVoiceNum) {
                    switchToNewVoice = true;
                    currentVoiceNum = newvoice;
                }
            }
            
            while (currentVoiceNum < voices.size()) {
                if (voices[currentVoiceNum]->currentMeasure->usedDuration > positionInMeasure) {
                    ++currentVoiceNum;
                    switchToNewVoice = true;
                } else
                    break;
            }
            
            if (currentVoiceNum >= voices.size()) {
                while (currentVoiceNum >= voices.size()) {
                    addVoice();
                }
                currentVoiceNum = voices.size() - 1;
            }
            
            if (switchToNewVoice) {
                
                finalizeChord();
                currentVoice = voices[currentVoiceNum];
                
                if (currentVoice->currentMeasure->usedDuration < positionInMeasure) {
                    t_rational restdur = positionInMeasure - currentVoice->currentMeasure->usedDuration;
                    chord *c = new chord(currentVoice, restdur);
                    addChord(c);
                    
                    finalizeChord();
                }
            }
            
            return switchToNewVoice;
        }
        
        t_llll *getClefsllll() {
            t_llll *ll = llll_get();
            for (auto v : voices) {
                llll_appendsym(ll, v->clef);
            }
            return ll;
        }
        
        t_llll *getKeysllll() {
            t_llll *ll = llll_get();
            for (auto v : voices) {
                llll_appendsym(ll, v->key);
            }
            return ll;
        }
        
        t_llll *getBodyllll() {
            t_llll *ll = llll_get();
            
            for (auto v : voices) {
                llll_appendllll(ll, v->getllll());
            }
            
            
            return ll;
        }
        
        virtual ~part() {
            theTimedThings.chordBased.deleteContents();
            if (hasMeasureInfo)
                theTimedThings.minfoBased.deleteContents();
        }
    };

    
    
    
    
    
    
    
    //////////////////////////
    //
    //  score members and methods
    //
    //////////////////////////
    
private:
    std::vector<part *> parts;
    part* currentPart;
    t_score *obj;
    
public:
    
    long dynamicsSlot;
    bool singleDyns;
    long directionsSlot;
    bool singleDirs;
    
    score(t_score *obj,
          long dynamicsSlot,
          long directionsSlot) :
        currentPart(nullptr),
        obj(obj),
        dynamicsSlot(dynamicsSlot),
        directionsSlot(directionsSlot)
    {
        if (dynamicsSlot)
            singleDyns = obj->r_ob.slotinfo[dynamicsSlot - 1].slot_singleslotfortiednotes;
        else
            singleDyns = false;
        
        if (directionsSlot)
            singleDirs = obj->r_ob.slotinfo[directionsSlot - 1].slot_singleslotfortiednotes;
        else
            singleDirs = false;
        
        
    }
    
    void addPart() {
        currentPart = new part(this, parts.size());
        parts.push_back(currentPart);
    }
    
    int addVoice() { return currentPart->addVoice(); }

    void pushLevel() { currentPart->pushLevel(); }
    
    void setClef(t_symbol *clef) { currentPart->setClef(clef); }
    
    void setKey(t_symbol *key) { currentPart->setKey(key); }
    void setKey(const char *key) { currentPart->setKey(key); }
    
    void createNewMeasure() { currentPart->createNewMeasure(); }
    
    void finalizeMeasure() { currentPart->finalizeMeasure(obj); }
    
    void backup(t_rational r) { currentPart->backup(r, obj); }
    
    void addChord(t_rational dur, bool grace = false) { currentPart->addChord(dur, grace); }
    void addChord(bool grace = false) {
        currentPart->addChord(grace);
    }
    
    const note* addNote(t_pitch pitch, int velocity, bool tie) { return currentPart->addNote(pitch, velocity, tie); }
    
    void addNoteSlot(int n, t_llll *slotll) { currentPart->setNoteSlot(n, slotll); }
    
    bool climbSafe() { return currentPart->climbSafe(); }
    
    void setChordDuration(t_rational dur) { currentPart->setChordDuration(dur); }
    
    void setChordSlot(int n, t_llll *slotll) { currentPart->setChordSlot(n, slotll); }
    
    void setBarline(t_llll* barlinell) { currentPart->setBarline(barlinell); }
    
    void setTimeSignature(mxml_node_t* attributesXML) {
        currentPart->setTimeSignature(attributesXML, obj);
    }
    
    void insertDirectionFromXML(mxml_node_t *directionXML, long divisions, long* velocity) {
        currentPart->insertDirectionFromXML(directionXML, divisions, velocity);
    }

    bool finalizeChord() {
        return currentPart->finalizeChord();
    }
    
    void adjustTimeSignatureIfNeeded() {
        currentPart->adjustTimeSignatureIfNeeded();
    }
    
    void finalizePart() {
        currentPart->finalize(singleDyns, singleDirs);
    }
    
    bool isThereAnOpenChord() {
        return currentPart->currentVoice->currentChord != nullptr;
    }
    
    bool updateCurrentVoice(mxml_node_t *itemXML) {
        return currentPart->updateCurrentVoice(itemXML);
    }
    
    t_rational getPositionInMeasure() {
        return currentPart->positionInMeasure;
    }
    
    t_llll *getllll() {
        t_llll *scorell = llll_get();
        llll_appendsym(scorell, _llllobj_sym_score);
        
        t_llll *clefsll = llll_get();
        llll_appendsym(clefsll, _llllobj_sym_clefs);
        t_llll *keysll = llll_get();
        llll_appendsym(keysll, _llllobj_sym_keys);
        t_llll *numpartsll = llll_get();
        llll_appendsym(numpartsll, _llllobj_sym_numparts);
        for (auto p : parts) {
            llll_chain(clefsll, p->getClefsllll());
            llll_chain(keysll, p->getKeysllll());
            llll_appendlong(numpartsll, p->getNumVoices());
        }
        llll_appendllll(scorell, clefsll);
        llll_appendllll(scorell, keysll);
        llll_appendllll(scorell, numpartsll);

        for (auto p : parts) {
            llll_chain(scorell, p->getBodyllll());
        }
        
        dev_llll_send(scorell, "xmldebug");
        return scorell;
    }

        
    virtual ~score() {
        for (auto p : parts)
            delete p;
    }
    
};


void score::timedThingContainer::insertDirectionFromXML(mxml_node_t *directionXML, t_rational global_position, long divisions, long* velocity, part* partOwner) {
    
    t_rational position;
    tempo* foundTempo = nullptr;
    mxml_node_t *offsetXML = mxmlFindElement(directionXML, directionXML, "offset", NULL, NULL, MXML_DESCEND_FIRST);

    std::vector<timedThing<voice>*> found;
    bool foundDynamics = false;
    
    if (offsetXML) {
        position = global_position + t_rational(mxmlGetInteger(offsetXML), divisions);
    } else {
        position = global_position;
    }
    
    for (mxml_node_t *typeXML = mxmlGetFirstChild(directionXML);
         typeXML;
         typeXML = mxmlWalkNext(typeXML, directionXML, MXML_NO_DESCEND)) {
        
        const char *typeName = mxmlGetElement(typeXML);
        if (!typeName)
            continue;
        
        if (!strcmp(typeName, "direction-type")) {
            for (mxml_node_t *itemXML = mxmlGetFirstChild(typeXML);
                 itemXML;
                 itemXML = mxmlWalkNext(itemXML, typeXML, MXML_NO_DESCEND)) {
                const char *itemName = mxmlGetElement(itemXML);
                if (!itemName)
                    continue;
                
                dynamics::types type = dynamics::types::standard;
                
                if (!strcmp(itemName, "dynamics") && itemXML->child) {
                    const char *itemContents = mxmlGetElement(itemXML->child);
                    if (itemContents && *itemContents) {
                        dynamics *dyn = new dynamics(itemContents, type, position, 0);
                        found.push_back(dyn);
                        foundDynamics = true;
                    }
                    
                } else if (!strcmp(itemName, "wedge")) {
                    char hairpin = 0;
                    const char *wedgetypetxt = mxmlElementGetAttr(itemXML, "type");
                    if (!strcmp(wedgetypetxt, "crescendo"))
                        hairpin = 1;
                    else if (!strcmp(wedgetypetxt, "diminuendo"))
                        hairpin = -1;
                    const char *dynamics_text;
                    
                    switch (hairpin) {
                        case 1:
                            dynamics_text = "<";
                            type = dynamics::types::wedge;
                            break;
                        case -1:
                            dynamics_text = ">";
                            type = dynamics::types::wedge;
                            break;
                        default:
                            dynamics_text = "|";
                            type = dynamics::types::wedgeEnd;
                            break;
                    }
                    
                    dynamics *dyn = new dynamics(dynamics_text, type, position, 0);
                    
                    found.push_back(dyn);
                    foundDynamics = true;
                    
                } else if (!strcmp(itemName, "words")) {
                    const char *itemContents = mxmlGetOpaque(itemXML);
                    if (itemContents && *itemContents) {
                        words *w = new words(itemContents, position, 0);
                        found.push_back(w);
                    }
                } else if (!strcmp(itemName, "metronome")) {
                    
                    mxml_node_t *beat_unitXML = mxmlFindElement(itemXML, directionXML, "beat-unit", NULL, NULL, MXML_DESCEND_FIRST);
                    if (beat_unitXML) {
                        const char *beat_unittxt = mxmlGetText(beat_unitXML, NULL);
                        long dots = 0;
                        mxml_node_t *beat_unit_dotXML;
                        for (beat_unit_dotXML = mxmlFindElement(beat_unitXML, directionXML, "beat-unit-dot", NULL, NULL, MXML_NO_DESCEND);
                             beat_unit_dotXML;
                             beat_unit_dotXML = mxmlFindElement(beat_unit_dotXML, directionXML, "beat-unit-dot", NULL, NULL, MXML_NO_DESCEND)) {
                            dots++;
                        }
                        
                        t_rational tempo_figure = xml_name_and_dots_to_value(beat_unittxt, dots);
                        double per_minute = 0;
                        
                        if (tempo_figure.r_num != 0) {
                            mxml_node_t *per_minuteXML = mxmlFindElement(itemXML, itemXML, "per-minute", NULL, NULL, MXML_DESCEND_FIRST);
                            if (per_minuteXML) {
                                const char *per_minutetxt = mxmlGetText(per_minuteXML, NULL);
                                if (per_minutetxt) {
                                    while (*per_minutetxt && !isdigit(*per_minutetxt))
                                        per_minutetxt++;
                                    per_minute = strtod(per_minutetxt, NULL);
                                }
                            }
                            else {
                                object_warn(nullptr, "Bad tempo, setting to 60");
                                per_minute = 60;
                            }
                            if (foundTempo)
                                remove(foundTempo);
                            foundTempo = new tempo(partOwner, position, 0, tempo_figure, per_minute);
                            insert(foundTempo);
                        } else
                            object_warn(nullptr, "Bad tempo");
                    }
                }
            }
        } else if (!strcmp(typeName, "sound") && !foundTempo) {
            if (const char* tempotxt = mxmlElementGetAttr(typeXML, "tempo"); tempotxt) {
                double bpm = strtod(tempotxt, NULL);
                foundTempo = new tempo(partOwner, position, 0, {1, 4}, bpm);
                insert(foundTempo);
            } else if (const char* velocitytxt = mxmlElementGetAttr(typeXML, "dynamics"); velocitytxt) {
                *velocity = strtod(velocitytxt, NULL) / 100. * 90.;
            }
        }
    }
    
    if (!foundDynamics) {
        for (auto f : found) {
            insert(f);
        }
    } else {
        for (auto f : found) {
            if (dynamics* d = dynamic_cast<dynamics*>(f)) {
                insert(d);
            } else if (words *w = dynamic_cast<words*>(f)) {
                d = new dynamics(w->txt, dynamics::types::standard, position, 0);
                insert(d);
                delete f;
            }
        }
    }
}


template<>
bool score::timedThing<score::voice>::cmp(const score::timedThing<score::voice>* a, const score::timedThing<score::voice>* b) {
    if (a->timePos < b->timePos)
        return true;
    else if (a->timePos > b->timePos)
        return false;
    else { // timePos are ==
        if (a->relativeX < b->relativeX)
            return true;
        else if (a->relativeX > b->relativeX)
            return false;
        else if (const chord* aChord = dynamic_cast<const chord*>(a)) {
            if (const chord* bChord = dynamic_cast<const chord*>(b)) {
                if (aChord->grace && !bChord->grace) // if both are chords
                    return true; // if a is a grace note and b is not, a must come first
                else
                    return false; // the other cases are either equal, or b must come first
            } else
                return true; // if a is a chord and b is not, a must come first
            
        } else if (const dynamics* aDyn = dynamic_cast<const dynamics*>(a)) {
            if (const dynamics* bDyn = dynamic_cast<const dynamics*>(b)) {
                if (aDyn->type == dynamics::types::wedgeEnd &&
                    bDyn->type != dynamics::types::wedgeEnd) {
                    return true; // if a is | and b is not, a must come first
                } else if (aDyn->type == dynamics::types::standard &&
                           bDyn->type == dynamics::types::wedge) {
                    return true; // if a is standard and b is a wedge, a must come first
                } else
                    return false; // the other cases are either equal, or b must come first
            } else
                return false; // if a is dynamics and b is words, the order is irrelevant
            
        } else
            return false; // the other cases are either equal, or b must come first
    }
}

template<>
bool score::timedThing<score::part>::cmp(const score::timedThing<score::part>* a, const score::timedThing<score::part>* b) {
    if (a->timePos < b->timePos)
        return true;
    else if (a->timePos > b->timePos)
        return false;
    else {
        if (a->relativeX < b->relativeX)
            return true;
        else if (a->relativeX > b->relativeX)
            return false;
        else {
            if (typeid(a) == typeid(score::measureinfo*) &&
                typeid(b) != typeid(score::measureinfo*)) {
                return true;
            } else
                return false;
        }
    }
}



score::chord::chord(voice *owner, bool grace) :
    timedThing<voice>(owner, owner->owner->globalPosition),
    levelChild(owner->currentMeasure->currentLevel),
    duration(t_rational{0, 1}),
    grace(grace),
    currentNote(nullptr),
    ties(0),
    rest(false)
{ }

score::chord::chord(voice *owner, t_rational dur, bool grace) : chord(owner, grace) {
    duration = dur;
}

void score::slotTimedThing::setOffset(bool singleSlotForTiedNotes) {
    t_rational dur;
    t_rational start;
    if (singleSlotForTiedNotes) {
        dur = refNote->tieEnd->prevDuration + refNote->tieEnd->owner->duration;
        start = refNote->tieStart->owner->timePos;
    } else {
        dur = refNote->owner->duration;
        start = refNote->owner->timePos;
    }
    offset = (timePos - start) / dur;
}


void score::tempo::setOffset() {
    offset = timePos - refMinfo->timePos;
}






t_llll *xml_get_words(mxml_node_t *from_this_node, mxml_node_t *stop_at_this_node, t_llll *words)
{
    mxml_node_t *tempXML = from_this_node;
    if (!words)
        words = llll_get();
    while (tempXML && tempXML != stop_at_this_node) {
        mxml_node_t *wordsXML = NULL;
        if ((wordsXML = mxmlFindElement(tempXML, tempXML, "words", NULL, NULL, MXML_DESCEND))) {
            const char *wordstxt = mxmlGetOpaque(wordsXML);
            if (wordstxt)
                llll_appendsym(words, gensym(wordstxt));
        }
        tempXML = tempXML->next;
    }
    return words;
}



t_shortRational xml_get_accidental(mxml_node_t *accXML)
{
    t_shortRational alter;
    if (!accXML)
        return t_pitch::natural;
    const char *accidentaltxt = mxmlGetText(accXML, NULL);
    
    if (!strcmp(accidentaltxt, "sharp"))
        alter = t_pitch::sharp;
    else if (!strcmp(accidentaltxt, "natural"))
        alter = t_pitch::natural;
    else if (!strcmp(accidentaltxt, "flat"))
        alter = t_pitch::flat;
    else if (!strcmp(accidentaltxt, "double-sharp"))
        alter = t_pitch::dblsharp;
    else if (!strcmp(accidentaltxt, "sharp-sharp"))
        alter = t_pitch::dblsharp;
    else if (!strcmp(accidentaltxt, "flat-flat"))
        alter = 2 * t_pitch::flat;
    else if (!strcmp(accidentaltxt, "sharp-sharp"))
        alter = t_pitch::dblsharp;
    else if (!strcmp(accidentaltxt, "natural-sharp"))
        alter = t_pitch::sharp;
    else if (!strcmp(accidentaltxt, "natural-flat"))
        alter = t_pitch::flat;
    else if (!strcmp(accidentaltxt, "quarter-flat"))
        alter = t_pitch::qrtrflat;
    else if (!strcmp(accidentaltxt, "quarter-sharp"))
        alter = t_pitch::qrtrsharp;
    else if (!strcmp(accidentaltxt, "three-quarters-flat"))
        alter = t_pitch::flat +  t_pitch::qrtrflat;
    else if (!strcmp(accidentaltxt, "three-quarters-sharp"))
        alter = t_pitch::sharp + t_pitch::qrtrsharp;
    else if (!strcmp(accidentaltxt, "sharp-down"))
        alter = t_pitch::qrtrsharp - t_pitch::eighthsharp;
    else if (!strcmp(accidentaltxt, "sharp-up"))
        alter = t_pitch::qrtrsharp + t_pitch::eighthsharp;
    else if (!strcmp(accidentaltxt, "natural-down"))
        alter = t_pitch::eighthflat;
    else if (!strcmp(accidentaltxt, "natural-up"))
        alter = t_pitch::eighthsharp;
    else if (!strcmp(accidentaltxt, "flat-down"))
        alter = t_pitch::qrtrflat + t_pitch::eighthflat;
    else if (!strcmp(accidentaltxt, "flat-up"))
        alter = t_pitch::eighthflat;
    else if (!strcmp(accidentaltxt, "triple-sharp"))
        alter = 3 * t_pitch::sharp;
    else if (!strcmp(accidentaltxt, "triple-flat"))
        alter = 3 * t_pitch::flat;
    else
        alter = t_pitch::natural;
    return alter;
}



t_llll *score_parse_articulations_to_llll(t_score *x, mxml_node_t *notationsXML, long articulationsslot)
{
    t_llll *articulationsll = llll_get();
    /* <!ELEMENT ornaments
     (((trill-mark | turn | delayed-turn | inverted-turn |
     delayed-inverted-turn | vertical-turn | shake |
     wavy-line | mordent | inverted-mordent | schleifer |
     tremolo | other-ornament), accidental-mark*)*)>
     */
    mxml_node_t *ornamentsXML;
    for (ornamentsXML = mxmlFindElement(notationsXML, notationsXML, "ornaments", NULL, NULL, MXML_DESCEND_FIRST);
         ornamentsXML;
         ornamentsXML = mxmlFindElement(ornamentsXML, notationsXML, "ornaments", NULL, NULL, MXML_NO_DESCEND)) {
        mxml_node_t *this_ornamentXML;
        for (this_ornamentXML = mxmlWalkNext(ornamentsXML, ornamentsXML, MXML_DESCEND_FIRST);
             this_ornamentXML;
             this_ornamentXML = mxmlWalkNext(this_ornamentXML, ornamentsXML, MXML_NO_DESCEND)) {
            char *ornament_txt = NULL;
            if (this_ornamentXML->type == MXML_ELEMENT)
                ornament_txt = this_ornamentXML->value.element.name;
            if (ornament_txt) {
                if (!strcmp(ornament_txt, "trill-mark"))
                    llll_appendsym(articulationsll, articulation_id2symbol(&x->r_ob.articulations_typo_preferences, k_ARTICULATION_TRILL), 0, WHITENULL_llll);
                else if (!strcmp(ornament_txt, "turn") ||
                         !strcmp(ornament_txt, "delayed-turn") ||
                         !strcmp(ornament_txt, "vertical-turn") ||
                         !strcmp(ornament_txt, "inverted-turn") ||
                         !strcmp(ornament_txt, "delayed-inverted-turn"))
                    llll_appendsym(articulationsll, articulation_id2symbol(&x->r_ob.articulations_typo_preferences, k_ARTICULATION_GRUPPETTO), 0, WHITENULL_llll);
                else if (!strcmp(ornament_txt, "mordent"))
                    llll_appendsym(articulationsll, articulation_id2symbol(&x->r_ob.articulations_typo_preferences, k_ARTICULATION_MORDENT_UP), 0, WHITENULL_llll);
                else if (!strcmp(ornament_txt, "inverted-mordent"))
                    llll_appendsym(articulationsll, articulation_id2symbol(&x->r_ob.articulations_typo_preferences, k_ARTICULATION_MORDENT_DOWN), 0, WHITENULL_llll);
                else if (!strcmp(ornament_txt, "wavy-line"))
                    llll_appendsym(articulationsll, articulation_id2symbol(&x->r_ob.articulations_typo_preferences, k_ARTICULATION_DOUBLE_MORDENT), 0, WHITENULL_llll);
                else if (!strcmp(ornament_txt, "tremolo")) {
                    switch (mxmlGetInteger(this_ornamentXML)) {
                        case 1:
                            llll_appendsym(articulationsll, articulation_id2symbol(&x->r_ob.articulations_typo_preferences, k_ARTICULATION_TREMOLO1), 0, WHITENULL_llll);
                            break;
                        case 2:
                            llll_appendsym(articulationsll, articulation_id2symbol(&x->r_ob.articulations_typo_preferences, k_ARTICULATION_TREMOLO2), 0, WHITENULL_llll);
                            break;
                        default:
                            llll_appendsym(articulationsll, articulation_id2symbol(&x->r_ob.articulations_typo_preferences, k_ARTICULATION_TREMOLO3), 0, WHITENULL_llll);
                            break;
                    }
                }
            }
        }
    }
    
    
    /*
     <!ELEMENT technical
     ((up-bow | down-bow | harmonic | open-string |
     thumb-position | fingering | pluck | double-tongue |
     triple-tongue | stopped | snap-pizzicato | fret |
     string | hammer-on | pull-off | bend | tap | heel |
     toe | fingernails | hole | arrow | handbell |
     other-technical)*)>
     */
    
    mxml_node_t *technicalXML;
    for (technicalXML = mxmlFindElement(notationsXML, notationsXML, "technical", NULL, NULL, MXML_DESCEND_FIRST);
         technicalXML;
         technicalXML = mxmlFindElement(technicalXML, notationsXML, "technical", NULL, NULL, MXML_NO_DESCEND)) {
        mxml_node_t *this_technicalXML;
        for (this_technicalXML = mxmlWalkNext(technicalXML, technicalXML, MXML_DESCEND_FIRST);
             this_technicalXML;
             this_technicalXML = mxmlWalkNext(this_technicalXML, technicalXML, MXML_NO_DESCEND)) {
            char *technical_txt = NULL;
            if (this_technicalXML->type == MXML_ELEMENT)
                technical_txt = this_technicalXML->value.element.name;
            if (technical_txt) {
                if (!strcmp(technical_txt, "harmonic"))
                    llll_appendsym(articulationsll, articulation_id2symbol(&x->r_ob.articulations_typo_preferences, k_ARTICULATION_HARMONIC), 0, WHITENULL_llll);
                else if (!strcmp(technical_txt, "tap"))
                    llll_appendsym(articulationsll, articulation_id2symbol(&x->r_ob.articulations_typo_preferences, k_ARTICULATION_LEFT_HAND_PIZZICATO), 0, WHITENULL_llll);
                else if (!strcmp(technical_txt, "up-bow"))
                    llll_appendsym(articulationsll, articulation_id2symbol(&x->r_ob.articulations_typo_preferences, k_ARTICULATION_BOWING_UP), 0, WHITENULL_llll);
                else if (!strcmp(technical_txt, "down-bow"))
                    llll_appendsym(articulationsll, articulation_id2symbol(&x->r_ob.articulations_typo_preferences, k_ARTICULATION_BOWING_DOWN), 0, WHITENULL_llll);
            }
        }
    }
    
    
    /*
     <!ELEMENT articulations
     ((accent | strong-accent | staccato | tenuto |
     detached-legato | staccatissimo | spiccato |
     scoop | plop | doit | falloff | breath-mark |
     caesura | stress | unstress | other-articulation)*)>
     */
    
    mxml_node_t *articulationsXML;
    for (articulationsXML = mxmlFindElement(notationsXML, notationsXML, "articulations", NULL, NULL, MXML_DESCEND_FIRST);
         articulationsXML;
         articulationsXML = mxmlFindElement(articulationsXML, notationsXML, "articulations", NULL, NULL, MXML_NO_DESCEND)) {
        mxml_node_t *this_articulationsXML;
        for (this_articulationsXML = mxmlWalkNext(articulationsXML, articulationsXML, MXML_DESCEND_FIRST);
             this_articulationsXML;
             this_articulationsXML = mxmlWalkNext(this_articulationsXML, articulationsXML, MXML_NO_DESCEND)) {
            char *articulations_txt = NULL;
            if (this_articulationsXML->type == MXML_ELEMENT)
                articulations_txt = this_articulationsXML->value.element.name;
            if (articulations_txt) {
                if (!strcmp(articulations_txt, "staccato"))
                    llll_appendsym(articulationsll, articulation_id2symbol(&x->r_ob.articulations_typo_preferences, k_ARTICULATION_STACCATO), 0, WHITENULL_llll);
                else if (!strcmp(articulations_txt, "tap"))
                    llll_appendsym(articulationsll, articulation_id2symbol(&x->r_ob.articulations_typo_preferences, k_ARTICULATION_LEFT_HAND_PIZZICATO), 0, WHITENULL_llll);
                else if (!strcmp(articulations_txt, "accent"))
                    llll_appendsym(articulationsll, articulation_id2symbol(&x->r_ob.articulations_typo_preferences, k_ARTICULATION_ACCENT), 0, WHITENULL_llll);
                else if (!strcmp(articulations_txt, "tenuto"))
                    llll_appendsym(articulationsll, articulation_id2symbol(&x->r_ob.articulations_typo_preferences, k_ARTICULATION_PORTATO), 0, WHITENULL_llll);
                else if (!strcmp(articulations_txt, "staccatissimo"))
                    llll_appendsym(articulationsll, articulation_id2symbol(&x->r_ob.articulations_typo_preferences, k_ARTICULATION_STACCATISSIMO), 0, WHITENULL_llll);
                else if (!strcmp(articulations_txt, "spiccato"))
                    llll_appendsym(articulationsll, articulation_id2symbol(&x->r_ob.articulations_typo_preferences, k_ARTICULATION_MARTELLATO), 0, WHITENULL_llll);
            }
        }
    }
    
    /*
     <!ELEMENT fermata  (#PCDATA)>
     */
    mxml_node_t *fermataXML = mxmlFindElement(notationsXML, notationsXML, "fermata", NULL, NULL, MXML_DESCEND_FIRST);
    if (fermataXML) {
        llll_appendsym(articulationsll, articulation_id2symbol(&x->r_ob.articulations_typo_preferences, k_ARTICULATION_FERMATA), 0, WHITENULL_llll);
    }
    
    if (articulationsll->l_size > 0) {
    ////     llll_prependlong(articulationsll, articulationsslot);
    } else {
        llll_free(articulationsll);
        articulationsll = NULL;
    }
    return articulationsll;
}


long xmlwrite_notehead_manage_filled(mxml_node_t *noteXML, mxml_node_t *noteheadXML,
                                     long filledID, long nonfilledID, long autoID)
{
    long noteheadID;
    mxml_node_t *filledXML = mxmlFindElement(noteheadXML, noteXML, "notehead", "filled", NULL, MXML_DESCEND_FIRST);
    if (filledXML) {
        const char *filledtxt = mxmlGetText(filledXML, NULL);
        if (!strcmp(filledtxt, "yes")) {
            noteheadID = filledID;
        } else if (!strcmp(filledtxt, "no")) {
            noteheadID = nonfilledID;
        } else
            noteheadID = autoID;
    } else
        noteheadID = autoID;
    return noteheadID;
}





t_symbol *xml_get_clef(t_score *x, mxml_node_t *attributesXML)
{
    long numclefs;
    long top_clef = k_CLEF_G, bottom_clef = k_CLEF_G, clef = k_CLEF_G;
    mxml_node_t *clefXML;
    for (numclefs = 0, clefXML = mxmlFindElement(attributesXML, attributesXML, "clef", NULL, NULL, MXML_DESCEND_FIRST);
         clefXML && numclefs < 16;
         numclefs++, clefXML = mxmlFindElement(clefXML, attributesXML, "clef", NULL, NULL, MXML_NO_DESCEND)) {
        mxml_node_t *signXML = mxmlFindElement(clefXML, clefXML, "sign", NULL, NULL, MXML_DESCEND_FIRST);
        mxml_node_t *lineXML = mxmlFindElement(clefXML, clefXML, "line", NULL, NULL, MXML_DESCEND_FIRST);
        mxml_node_t *clef_octave_changeXML = mxmlFindElement(clefXML, clefXML, "clef-octave-change", NULL, NULL, MXML_DESCEND_FIRST);
        const char *sign = "";
        long line = -1, clef_octave_change = 0;
        long this_clef = k_CLEF_G;
        if (signXML)
            sign = mxmlGetText(signXML, 0);
        if (lineXML)
            line = mxmlGetInteger(lineXML);
        if (clef_octave_changeXML)
            clef_octave_change = mxmlGetInteger(clef_octave_changeXML);
        if (!strcmp(sign, "G")) {
            if (clef_octave_change == 1)        this_clef = k_CLEF_G8va;
            else if (clef_octave_change > 1)    this_clef = k_CLEF_G15ma;
            else                                this_clef = k_CLEF_G;
        } else if (!strcmp(sign, "F")) {
            if (line == 3)
                this_clef = k_CLEF_BARYTONE;
            else {
                if (clef_octave_change == -1)        this_clef = k_CLEF_F8vb;
                else if (clef_octave_change < -1)    this_clef = k_CLEF_F15mb;
                else                                this_clef = k_CLEF_F;
            }
        } else if (!strcmp(sign, "C")) {
            switch (line) {
                case 1:        this_clef = k_CLEF_SOPRANO;    break;
                case 2:        this_clef = k_CLEF_MEZZO;    break;
                case 3:        this_clef = k_CLEF_ALTO;    break;
                case 4:        this_clef = k_CLEF_TENOR;    break;
                default:    this_clef = k_CLEF_MEZZO;    break;
            }
        } else if (!strcmp(sign, "percussion")) {
            this_clef = k_CLEF_PERCUSSION;
        } else {
            this_clef = k_CLEF_NONE;
        }
        
        if (numclefs == 0 || (this_clef > k_CLEF_PERCUSSION && this_clef < top_clef))
            top_clef = this_clef;
        if (numclefs == 0 || this_clef > bottom_clef)
            bottom_clef = this_clef;
    }
    // k_CLEF_PERCUSSION and k_CLEF_NO can only exist if top_clef and bottom_clef are the same
    if (top_clef == bottom_clef) {
        clef = top_clef;
    } else {
        if (top_clef <= k_CLEF_G8va) {
            if (bottom_clef <= k_CLEF_G)
                clef = k_CLEF_GG;
            else if (bottom_clef <= k_CLEF_F)
                clef = k_CLEF_FGG;
            else
                clef = k_CLEF_FFGG;
        } else if (top_clef == k_CLEF_G) {
            if (bottom_clef <= k_CLEF_F)
                clef = k_CLEF_FG;
            else
                clef = k_CLEF_FFG;
        } else
            clef = k_CLEF_FF;
    }
    return clef_number_to_clef_symbol((t_notation_obj *) x, clef);
}



t_symbol *xml_get_key_signature(t_score *x, mxml_node_t *attributesXML)
{
    t_symbol *keysym;
    mxml_node_t *keyXML = mxmlFindElement(attributesXML, attributesXML, "key", NULL, NULL, MXML_DESCEND_FIRST);
    if (keyXML) {
        mxml_node_t *fifthsXML = mxmlFindElement(keyXML, keyXML, "fifths", NULL, NULL, MXML_DESCEND_FIRST);
        if (fifthsXML) {
            long fifths = mxmlGetInteger(fifthsXML);
            e_modes mode = k_MODE_MAJOR;
            mxml_node_t *modeXML = mxmlFindElement(keyXML, keyXML, "mode", NULL, NULL, MXML_DESCEND_FIRST);
            const char *mode_txt = mxmlGetText(modeXML, NULL);
            if (mode_txt && !strcmp(mode_txt, "minor"))
                mode = k_MODE_MINOR;
            keysym = key_and_mode_to_sym((t_notation_obj *) x, fifths, mode, NULL);
            // we're gonna append this later
        } else {
            t_rational acc_pattern[7];
            long i;
            for (i = 0; i < 7; i++)
                acc_pattern[i] = long2rat(0);
            mxml_node_t *key_stepXML;
            for (key_stepXML = mxmlFindElement(keyXML, keyXML, "key-step", NULL, NULL, MXML_DESCEND_FIRST);
                 key_stepXML;
                 key_stepXML = mxmlFindElement(key_stepXML, key_stepXML, "key-step", NULL, NULL, MXML_NO_DESCEND)) {
                mxml_node_t *key_alterXML = mxmlFindElement(key_stepXML, key_stepXML, "key-alter", NULL, NULL, MXML_NO_DESCEND);
                double alter_dbl = mxmlGetReal(key_alterXML);
                char key_char = mxmlGetText(key_stepXML, NULL)[0];
                key_char = key_char >= 'a' ? key_char - 'a' : key_char - 'A';
                long step = (key_char + 5) % 7;
                acc_pattern[step] = approx_double_with_rat_fixed_den(alter_dbl, 100, 1, NULL);
            }
            keysym = key_and_mode_to_sym((t_notation_obj *) x, 0, k_MODE_NONSTANDARD, acc_pattern);
            // we're gonna append this later
        }
    } else {
        keysym = gensym("CM");
        // we're gonna append this later
    }
    return keysym;
}

void xml_get_divisions(t_score *x, mxml_node_t *attributesXML, long *divisions)
{
    long d = 0;
    mxml_node_t *divisionsXML = mxmlFindElement(attributesXML, attributesXML, "divisions", NULL, NULL, MXML_DESCEND_FIRST);
    if (divisionsXML) {
        d = mxmlGetInteger(divisionsXML) * 4;
        if (d)
            *divisions = d;
    }
    if (*divisions == 0) {
        object_warn((t_object *) x, "Tag <divisions> missing or corrupted");
        *divisions = 4;
    } 
}

t_llll *xml_get_tempi(t_score *x, mxml_node_t *measureXML, long divisions, t_bool isfirstmeasure, t_llll* &maintempo_ll)
{
    // if tempill already has a value, it has already been used
    t_llll *tempill = llll_get();
    mxml_node_t *directionXML;
    for (directionXML = mxmlFindElement(measureXML, measureXML, "direction", NULL, NULL, MXML_DESCEND_FIRST);
         directionXML;
         directionXML = mxmlFindElement(directionXML, measureXML, "direction", NULL, NULL, MXML_NO_DESCEND)) {
        
        mxml_node_t *direction_typeXML;
        for (direction_typeXML = mxmlFindElement(directionXML, directionXML, "direction-type", NULL, NULL, MXML_DESCEND_FIRST);
             direction_typeXML;
             direction_typeXML = mxmlFindElement(direction_typeXML, directionXML, "direction-type", NULL, NULL, MXML_NO_DESCEND)) {
            
            mxml_node_t *metronomeXML = mxmlFindElement(direction_typeXML, direction_typeXML, "metronome", NULL, NULL, MXML_DESCEND_FIRST);
            if (metronomeXML) {
                t_llll *onetempoll = llll_get();
                mxml_node_t *beat_unitXML = mxmlFindElement(metronomeXML, directionXML, "beat-unit", NULL, NULL, MXML_DESCEND_FIRST);
                if (beat_unitXML) {
                    const char *beat_unittxt = mxmlGetText(beat_unitXML, NULL);
                    long dots = 0;
                    mxml_node_t *beat_unit_dotXML;
                    for (beat_unit_dotXML = mxmlFindElement(beat_unitXML, directionXML, "beat-unit-dot", NULL, NULL, MXML_NO_DESCEND);
                         beat_unit_dotXML;
                         beat_unit_dotXML = mxmlFindElement(beat_unit_dotXML, directionXML, "beat-unit-dot", NULL, NULL, MXML_NO_DESCEND))
                        dots++;
                    
                    t_rational tempo_figure = xml_name_and_dots_to_value(beat_unittxt, dots);
                    if (tempo_figure.r_num != 0) {
                        llll_appendrat(onetempoll, tempo_figure, 0, WHITENULL_llll);
                        mxml_node_t *per_minuteXML = mxmlFindElement(metronomeXML, metronomeXML, "per-minute", NULL, NULL, MXML_DESCEND_FIRST);
                        if (per_minuteXML) {
                            const char *per_minutetxt = mxmlGetText(per_minuteXML, NULL);
                            double per_minute = 0;
                            if (per_minutetxt) {
                                while (*per_minutetxt && !isdigit(*per_minutetxt))
                                    per_minutetxt++;
                                per_minute = strtod(per_minutetxt, NULL);
                            }
                            llll_appenddouble(onetempoll, per_minute, 0, WHITENULL_llll);
                        }
                        else {
                            object_warn((t_object *) x, "Bad tempo, setting to 60");
                            llll_appendlong(onetempoll, 60, 0, WHITENULL_llll);
                        }
                        
                        mxml_node_t *offsetXML = mxmlFindElement(directionXML, directionXML, "offset", NULL, NULL, MXML_DESCEND_FIRST);
                        t_rational offset;
                        if (offsetXML) {
                            offset = genrat(mxmlGetInteger(offsetXML), divisions);
                        } else {
                            offset = genrat(0, 1);
                        }
                        llll_appendrat(onetempoll, offset, 0, WHITENULL_llll);
                        llll_appendlong(onetempoll, 0, 0, WHITENULL_llll); // tempo interpolation
                        if (isfirstmeasure && !maintempo_ll && offset.r_num == 0) {
                            maintempo_ll = llll_get();
                            llll_appendllll_clone(maintempo_ll, onetempoll);
                        }
                        llll_appendllll(tempill, onetempoll, 0, WHITENULL_llll);
                    } else
                        object_warn((t_object *) x, "Bad tempo");
                }
            }
        }
        mxml_node_t *soundtempoXML = mxmlFindElement(directionXML, directionXML, "sound", "tempo", NULL, MXML_DESCEND_FIRST);
        if (!soundtempoXML)
            soundtempoXML = mxmlFindElement(measureXML, measureXML, "sound", "tempo", NULL, MXML_DESCEND_FIRST);
        if (soundtempoXML) {
            t_llll *onetempoll = llll_get();
            double bpm = strtod(mxmlElementGetAttr(soundtempoXML, "tempo"), NULL);
            llll_appendrat(onetempoll, genrat(1, 4), 0, WHITENULL_llll);
            llll_appenddouble(onetempoll, bpm, 0, WHITENULL_llll);
            mxml_node_t *offsetXML = NULL;
            t_rational offset;
            if (directionXML)
                offsetXML = mxmlFindElement(directionXML, directionXML, "offset", NULL, NULL, MXML_DESCEND_FIRST);
            if (offsetXML) {
                offset = genrat(mxmlGetInteger(offsetXML), divisions);
            } else {
                offset = genrat(0, 1);
            }
            llll_appendrat(onetempoll, offset, 0, WHITENULL_llll);
            if (isfirstmeasure && !maintempo_ll && offset.r_num == 0) {
                maintempo_ll = llll_get();
                llll_appendllll_clone(maintempo_ll, onetempoll);
            }
            llll_appendllll(tempill, onetempoll, 0, WHITENULL_llll);
        }
    }
    return tempill;
}

t_llll *xml_get_barline(mxml_node_t *measureXML)
{
    mxml_node_t *barlineXML = mxmlFindElement(measureXML, measureXML, "barline", NULL, NULL, MXML_DESCEND_FIRST);
    if (barlineXML) {
        mxml_node_t *barstyleXML = mxmlFindElement(barlineXML, barlineXML, "bar-style", NULL, NULL, MXML_DESCEND_FIRST);
        if (barstyleXML) {
            const char *bar_styletxt = mxmlGetText(barstyleXML, NULL);
            char barline[2];
            barline[1] = 0;
            if (!strcmp(bar_styletxt, "regular"))            *barline = k_BARLINE_NORMAL;
            else if (!strcmp(bar_styletxt, "dashed"))        *barline = k_BARLINE_DASHED;
            else if (!strcmp(bar_styletxt, "dotted"))        *barline = k_BARLINE_POINTS;
            else if (!strcmp(bar_styletxt, "light-light"))    *barline = k_BARLINE_DOUBLE;
            else if (!strcmp(bar_styletxt, "light-heavy"))    *barline = k_BARLINE_FINAL;
            else if (!strcmp(bar_styletxt, "none"))            *barline = k_BARLINE_HIDDEN;
            else if (!strcmp(bar_styletxt, "heavy"))        *barline = k_BARLINE_SOLID;
            else if (!strcmp(bar_styletxt, "tick"))        *barline = k_BARLINE_TICK;
            else *barline = 0;
            t_llll *barlinell = llll_get();
            llll_appendsym(barlinell, _llllobj_sym_barline, 0, WHITENULL_llll);
            if (*barline)
                llll_appendsym(barlinell, gensym(barline), 0, WHITENULL_llll);
            else
                llll_appendlong(barlinell, 0, 0, WHITENULL_llll);
            //// llll_appendllll(measureinfoll, barlinell, 0, WHITENULL_llll);
            return barlinell;
        }
    }
    return nullptr;
}



t_llll *score_readxmlbuffer(t_score *x,
                            char* buffer,
                            long parenthesizedquartertones,
                            long lyricsslot,
                            long noteheadslot,
                            long articulationsslot,
                            long dynamicsslot,
                            long directionsslot)
{
    long new_tonedivision = 2;
    t_bool startfromzero = false;
    mxml_node_t *scoreXML = mxmlLoadString(NULL, (char *) buffer, xml_load_cb);
    
    mxml_node_t *score_partwiseXML = mxmlFindElement(scoreXML, scoreXML, "score-partwise", NULL, NULL, MXML_DESCEND_FIRST);
    if (!score_partwiseXML) {
        object_error((t_object *) x, "File is not a partwise MusicXML!");
        return NULL;
    }
    
    //// t_llll *scorell = llll_get();
    //// llll_appendsym(scorell, _llllobj_sym_score, 0, WHITENULL_llll);
    
    score theScore(x, dynamicsslot, directionsslot);
    
    // parse all the header stuff
    mxml_node_t *part_listXML = mxmlFindElement(score_partwiseXML, score_partwiseXML, "part-list", NULL, NULL, MXML_DESCEND_FIRST);
    if (!part_listXML) {
        object_error((t_object *) x, "Missing <part-list> tag");
        //llll_free(scorell);
        return NULL;
    }
    
    //// t_llll *clefsll = llll_get();
    //// llll_appendsym(clefsll, _llllobj_sym_clefs, 0, WHITENULL_llll);
    //// llll_appendllll(scorell, clefsll, 0, WHITENULL_llll);
    
    //// t_llll *keysll = llll_get();
    //// llll_appendsym(keysll, _llllobj_sym_keys, 0, WHITENULL_llll);
    //// llll_appendllll(scorell, keysll, 0, WHITENULL_llll);
    
    //// t_llll *numpartsll = llll_get();
    //// llll_appendsym(numpartsll, _llllobj_sym_numparts, 0, WHITENULL_llll);
    //// llll_appendllll(scorell, numpartsll);
    
    // iterate on the parts
    mxml_node_t *partXML;
    long partnum = 1; // for debug
    for (partXML = mxmlFindElement(score_partwiseXML, score_partwiseXML, "part", NULL, NULL, MXML_DESCEND_FIRST);
         partXML;
         partXML = mxmlFindElement(partXML, score_partwiseXML, "part", NULL, NULL, MXML_NO_DESCEND), partnum++) {
        
        //// t_llll *voicell[CONST_MAX_VOICES];
        //// voicell[0] = llll_get();
        //// voicell[1] = llll_get();
        
        theScore.addPart();
        
        long divisions = 0;
        long velocity = 90;
        //// t_llll *timell = NULL;
        //// t_llll *tempill = NULL;
        // iterate on the measures for this part
        mxml_node_t *measureXML;
        long isfirstmeasure = 1;
        long measure_number;
        
       //// char dynamics_text[CONST_DYNAMICS_TEXT_ALLOC_SIZE];
        
        //// dynamics_text[0] = 0;
        //// t_llll *words = NULL;
        //// t_symbol *clefsym, *keysym;
        
        for (measureXML = mxmlFindElement(partXML, partXML, "measure", NULL, NULL, MXML_DESCEND_FIRST);
             measureXML;
             measureXML = mxmlFindElement(measureXML, partXML, "measure", NULL, NULL, MXML_NO_DESCEND), measure_number++) {
            
            //// t_llll *measurell[CONST_MAX_VOICES];
            //// t_rational used_duration[CONST_MAX_VOICES];
            
            //// for (long i = 0; i <= voices_for_this_xml_part; i++) {
                //// measurell[i] = llll_get();
                //// used_duration[i] = t_rational(0);
            //// }
            
            if (isfirstmeasure) {
                const char* number = mxmlElementGetAttr(measureXML, "number");
                if (number) {
                    int n = atoi(number);
                    if (n == 0) {
                        measure_number = 0;
                        startfromzero = true;
                    } else {
                        measure_number = 1;
                    }
                }
            }
            
            //measure theMeasure;
            theScore.createNewMeasure();
            
            //t_rational current_timepoint = t_rational(0);
            
            //// t_llll *measureinfoll = llll_get();
            mxml_node_t *attributesXML = mxmlFindElement(measureXML, measureXML, "attributes", NULL, NULL, MXML_DESCEND_FIRST);
            //// t_llll *newtimell = nullptr;
            // parse the attributes:
            if (attributesXML) {
                if (isfirstmeasure) {
                    theScore.setClef(xml_get_clef(x, attributesXML));
                    theScore.setKey(xml_get_key_signature(x, attributesXML));
                }
                
                xml_get_divisions(x, attributesXML, &divisions);
 
            } else if (isfirstmeasure) {
                object_warn((t_object *) x, "Tag <divisions> missing or corrupted");
                divisions = 4;
                theScore.setClef(_llllobj_sym_G);
                theScore.setKey("CM");
            }
            
            theScore.setTimeSignature(attributesXML);
            
            /*
            // tempi ---- TODO
            tempill = xml_get_tempi(x, measureXML, divisions, isfirstmeasure, maintempo_ll);

            if (tempill->l_size) {
                llll_appendllll(measureinfoll, tempill, 0, WHITENULL_llll);
            } else if (maintempo_ll) {
                llll_clone_upon(maintempo_ll, tempill);
                llll_appendllll(measureinfoll, tempill, 0, WHITENULL_llll);
            } else {
                llll_free(tempill);
                tempill = NULL;
            }
            */
            
            
            ///////////////////////////////
            ///////////////////////////////
            //
            // things in measure: chords, notes and more
            //
            ///////////////////////////////
            ///////////////////////////////
            
            //// mxml_node_t *nextnoteXML = NULL;
            
            //// mxml_node_t *firstnoteXML = NULL;
            //// t_llll *chordll = NULL;
            //// t_llll *chord_parentll[CONST_MAX_VOICES];
            
            //// for (long i = 0; i < voices_for_this_xml_part; i++)
                //// chord_parentll[i] = measurell[i];
            //            chord_parentll[0] = measurell[0];
            bool grace_group = 0, grace = 0;
            long pops = 0;
            //// t_llll *chordslotsll = NULL;
            
            //// long current_voice_in_part = 0;
            
            
            class t_pitchWithOnset : public t_pitch {
            public:
                t_rational onset;
                t_pitchWithOnset(t_pitch p, t_rational o) : t_pitch(p), onset(o) { };
                t_pitchWithOnset() { };
            };
            
            //auto allpitches = new t_pitchWithOnset[10000];
            
            t_pitchWithOnset allpitches[10000];
            long numpitches = 0;
            
            mxml_node_t *itemXML;
            for (itemXML = mxmlGetFirstChild(measureXML);
                 itemXML;
                 itemXML = mxmlWalkNext(itemXML, measureXML, MXML_NO_DESCEND)) {
                
                t_bool switch_to_new_voice = false;
                //mxml_node_t *nextnode = noteXML;
                t_bool isrest = false;
                const char *itemName = mxmlGetElement(itemXML);
                if (!itemName)
                    continue;
                
                // should we consider sound -> tempo as well?
                if (!strcmp(itemName, "forward")) {
                    
                    isrest = true;
                    
                } else if (!strcmp(itemName, "backup")) {
                    
                    mxml_node_t *durationXML = mxmlFindElement(itemXML, itemXML, "duration", NULL, NULL, MXML_DESCEND_FIRST);
                    t_rational backupdur = t_rational(mxmlGetInteger(durationXML), divisions);
                    
                    theScore.backup(backupdur);
                    
                    //// current_timepoint -= backupdur;
                    //// global_position -= backupdur;
                    
                    //// //t_rational getHere = used_duration[current_voice_in_part] - backupdur;
                    //// if (current_timepoint < 0) {
                    ////     object_warn((t_object *) x, "<backup> tag wants to backup too far");
                    ////     current_timepoint = t_rational(0);
                    //// }
                    switch_to_new_voice = true;
                    continue;
                    
                } else if (!strcmp(itemName, "direction")) {
                    
                    // here we also need to deal with tempi,
                    // so this part must be refactored
                    
                    theScore.insertDirectionFromXML(itemXML, divisions, &velocity);
                    continue;
                
                } else if (strcmp(itemName, "note")) {
                    continue;
                }
                
                //// if (!firstnoteXML)
                ////     firstnoteXML = itemXML;
                
                //// nextnoteXML = mxmlFindElement(itemXML, measureXML, "note", NULL, NULL, MXML_NO_DESCEND);
                
                //// bool switchedToNewVoice =
                theScore.updateCurrentVoice(itemXML);
                
                //// // if there is a chord and we're closing (even if temporarily) this voice,
                //// // append to it its articulations and flags
                //// if (currentChord && switchToNewVoices) {
                ////     if (chordslotsll) {
                ////         currentChord->slots = chordslotsll;
                ////     }
                ////     currentChord = nullptr;
                //// }
                
                mxml_node_t *chordXML = mxmlFindElement(itemXML, itemXML, "chord", NULL, NULL, MXML_DESCEND_FIRST);
                //// if (chordXML && !currentChord) {
                ////     object_warn((t_object *) x, "<chord> tag with no preceding note");
                ////     chordXML = nullptr;
                //// }
                
                mxml_node_t *notationsXML = mxmlFindElement(itemXML, itemXML, "notations", NULL, NULL, MXML_DESCEND_FIRST);
                
                t_pitch pch;
                
                if (!chordXML) {
                    //// if (currentChord) { // if there was a previous chord, append its flags to it
                    ////     if (chordslotsll) {
                    ////         currentChord->slots = chordslotsll;
                    ////         chordslotsll = nullptr;
                    ////     }
                    ////     currentChord = nullptr;
                    //// }
                    
                    theScore.finalizeChord();
                    
                    grace = mxmlFindElement(itemXML, itemXML, "grace", NULL, NULL, MXML_DESCEND_FIRST) != 0;
                    if (grace && !grace_group) { // that is, we're starting a new grace group
                        
                        theScore.pushLevel();
                        grace_group = true;
                        
                    } else if (!grace && grace_group) { // that is, this is the first note outside a grace group
                        theScore.climbSafe();
                        grace_group = false;
                        
                    }
                    
                    while (pops) {
                        if (theScore.climbSafe()) {
                            pops--;
                        } else
                            pops = 0;
                    }
                    

                    
                    // level stuff
                    mxml_node_t *beamXML;
                    for (beamXML = mxmlFindElement(itemXML, itemXML, "beam", NULL, NULL, MXML_DESCEND_FIRST);
                         beamXML;
                         beamXML = mxmlFindElement(beamXML, itemXML, "beam", NULL, NULL, MXML_NO_DESCEND)) {
                        const char *beamtxt = mxmlGetText(beamXML, NULL);
                        if (!strcmp(beamtxt, "begin")) {
                            theScore.pushLevel();
                        } else if (!strcmp(beamtxt, "end")) {
                            pops++;
                        }
                    }
                    
                    mxml_node_t *tupletXML;
                    for (tupletXML = mxmlFindElement(notationsXML, notationsXML, "tuplet", NULL, NULL, MXML_DESCEND_FIRST);
                         tupletXML;
                         tupletXML = mxmlFindElement(tupletXML, notationsXML, "tuplet", NULL, NULL, MXML_NO_DESCEND)) {
                        const char *tuplettypetxt = mxmlElementGetAttr(tupletXML, "type");
                        if (!strcmp(tuplettypetxt, "start")) {
                            theScore.pushLevel();
                        } else if (!strcmp(tuplettypetxt, "stop")) {
                            pops++;
                        }
                    }
                    
                    //// chordll = llll_get();
                    //// llll_appendllll(chord_parentll[current_voice_in_part], chordll, 0, WHITENULL_llll);
                    
                    theScore.addChord(grace);

                    mxml_node_t *restXML = mxmlFindElement(itemXML, itemXML, "rest", NULL, NULL, MXML_DESCEND_FIRST);
                    if (restXML)
                        isrest = true;
                    t_rational duration = t_rational(0);
                    
                    mxml_node_t *typeXML = mxmlFindElement(itemXML, itemXML, "type", NULL, NULL, MXML_DESCEND_FIRST);
                    if (typeXML) {
                        const char *typetxt = mxmlGetText(typeXML, NULL);
                        long dots = 0;
                        mxml_node_t *dotXML;
                        for (dotXML = mxmlFindElement(typeXML, itemXML, "dot", NULL, NULL, MXML_NO_DESCEND);
                             dotXML;
                             dotXML = mxmlFindElement(dotXML, itemXML, "dot", NULL, NULL, MXML_NO_DESCEND))
                            dots++;
                        
                        duration = xml_name_and_dots_to_value(typetxt, dots);
                    }
                    if ((!typeXML && !grace) || (restXML && duration == 1)) { // it could be the only note in the part
                        mxml_node_t *durationXML = mxmlFindElement(itemXML, itemXML, "duration", NULL, NULL, MXML_DESCEND_FIRST);
                        if (durationXML)
                            duration = genrat(mxmlGetInteger(durationXML), divisions);
                        else if (duration == t_rational(0)) {
                            object_warn((t_object *) x, "Note without duration");
                            duration = genrat(1, 4); // use a dummy duration!
                        }
                    } else if (!typeXML && grace) { // if it's a grace note and there is no type
                        duration = genrat(1, 8); // use a dummy duration!
                    }
                    
                    mxml_node_t *time_modificationXML = mxmlFindElement(itemXML, itemXML, "time-modification", NULL, NULL, MXML_DESCEND_FIRST);
                    if (time_modificationXML) {
                        mxml_node_t *actual_notesXML = mxmlFindElement(time_modificationXML, time_modificationXML, "actual-notes", NULL, NULL, MXML_DESCEND_FIRST);
                        mxml_node_t *normal_notesXML = mxmlFindElement(time_modificationXML, time_modificationXML, "normal-notes", NULL, NULL, MXML_DESCEND_FIRST);
                        mxml_node_t *normal_typeXML = mxmlFindElement(time_modificationXML, time_modificationXML, "normal-type", NULL, NULL, MXML_DESCEND_FIRST);
                        long actual_notes = mxmlGetInteger(actual_notesXML);
                        long normal_notes = mxmlGetInteger(normal_notesXML);
                        if (!typeXML && normal_typeXML) {
                            const char *normal_typetxt = mxmlGetText(normal_typeXML, NULL);
                            long normal_dots = 0;
                            mxml_node_t *normal_dotXML;
                            for (normal_dotXML = mxmlFindElement(normal_typeXML, itemXML, "normal-dot", NULL, NULL, MXML_NO_DESCEND);
                                 normal_dotXML;
                                 normal_dotXML = mxmlFindElement(normal_dotXML, itemXML, "normal-dot", NULL, NULL, MXML_NO_DESCEND))
                                normal_dots++;
                            
                            duration = xml_name_and_dots_to_value(normal_typetxt, normal_dots);
                        }
                        duration = rat_long_prod(duration, normal_notes);
                        duration = rat_long_div(duration, actual_notes);
                    }
                    theScore.setChordDuration(duration);
                    ////theTimedThingContainer.insertChord(chordll, global_position, current_voice_in_part);
                    
                    //// if (!grace) {
                        //// //current_timepoint = used_duration[current_voice_in_part] += duration;
                        //// global_position += duration;
                    //// }
                    
                    //// if (isrest) { // which can be either because it is an actual rest, or beacuse of <forward>
                        //// duration.r_num *= -1;
                    //// }
                    //// llll_appendrat(chordll, duration, 0, WHITENULL_llll);
                    
                    
                    
                    
                }
                
                if (!isrest) {
                    mxml_node_t *pitchXML = mxmlFindElement(itemXML, itemXML, "pitch", NULL, NULL, MXML_DESCEND_FIRST);
                    const char *steptxt = NULL;
                    long octave = 0;
                    short degree = 0;
                    t_shortRational alter;
                    
                    if (pitchXML) {
                        t_rational currOnset = theScore.getPositionInMeasure();
                        mxml_node_t *stepXML = mxmlFindElement(pitchXML, pitchXML, "step", NULL, NULL, MXML_DESCEND_FIRST);
                        mxml_node_t *alterXML = mxmlFindElement(pitchXML, pitchXML, "alter", NULL, NULL, MXML_DESCEND_FIRST);
                        mxml_node_t *octaveXML = mxmlFindElement(pitchXML, pitchXML, "octave", NULL, NULL, MXML_DESCEND_FIRST);
                        steptxt = mxmlGetText(stepXML, NULL);
                        degree = toupper(*steptxt) - 'C';
                        if (degree < 0)
                            degree += 7;
                        CLAMP(degree, 0, 6);
                        alter = approx_double_with_rat_fixed_den(mxmlGetReal(alterXML) / 2., 8, 0, nullptr);
                        octave = mxmlGetInteger(octaveXML) + 1;
                        mxml_node_t *accidentalXML = mxmlFindElement(itemXML, itemXML, "accidental", NULL, NULL, MXML_DESCEND_FIRST);
                        if (accidentalXML) {
                            alter = xml_get_accidental(accidentalXML);
                        }
                        short den = alter.den();
                        if (den > new_tonedivision)
                            new_tonedivision = den;
                        if (den <= 2 && parenthesizedquartertones) {
                            const char *parentheses = mxmlElementGetAttr(accidentalXML, "parentheses");
                            if (parentheses && !strcmp(parentheses, "yes")) {
                                alter += t_pitch::qrtrsharp;
                                if (new_tonedivision < 4)
                                    new_tonedivision = 4;
                            } else {
                                // this could be a quarter-tone with an implicit accidental,
                                // as in the sequence C+ C(+)
                                for (long i = numpitches - 1; i >= 0; i--) {
                                    if (allpitches[i].degree() == degree &&
                                        allpitches[i].octave() == octave &&
                                        allpitches[i].onset < currOnset &&
                                        ((!accidentalXML && alter == 0) ||
                                         allpitches[i].alter() == alter - t_pitch::qrtrsharp)) {
                                            alter = allpitches[i].alter();
                                            break;
                                        }
                                }
                            }
                        }
                        /*
                         // If a note bears no alteration and no accidentals
                         // and parenthesizedquartertones is off
                         // consider it altered if there was a previously altered note anyway
                         // (AA COMMENTED IT OUT ON SEP 3 2020 - NOW IT IS CONSIDERED NATURAL)
                         else if (!accidentalXML && alter == 0) {
                            for (long i = numpitches - 1; i >= 0; i--) {
                                if (allpitches[i].degree() == degree &&
                                    allpitches[i].octave() == octave) {
                                    alter = allpitches[i].alter();
                                    break;
                                }
                            }
                        }*/
                        
                        pch = t_pitch(degree, alter, octave);
                        allpitches[numpitches++] = { pch, currOnset };
                        
                        
                    } else {
                        mxml_node_t *unpitchedXML = mxmlFindElement(itemXML, itemXML, "unpitched", NULL, NULL, MXML_DESCEND_FIRST);
                        if (unpitchedXML) {
                            mxml_node_t *display_stepXML = mxmlFindElement(unpitchedXML, unpitchedXML, "display-step", NULL, NULL, MXML_DESCEND_FIRST);
                            if (display_stepXML) {
                                mxml_node_t *display_octaveXML = mxmlFindElement(unpitchedXML, unpitchedXML, "display-octave", NULL, NULL, MXML_DESCEND_FIRST);
                                steptxt = mxmlGetText(display_stepXML, NULL);
                                degree = toupper(*steptxt) - 'C';
                                if (degree < 0)
                                    degree += 7;
                                CLAMP(degree, 0, 6);
                                octave = mxmlGetInteger(display_octaveXML) + 1;
                            } else {
                                degree = 6;
                                octave = 5;
                            }
                        }
                        pch = t_pitch(degree, alter, octave);

                    }
                    
                    //// t_llll *notell = llll_get();

                    //// llll_appendpitch(notell, pch);
                
                    //// llll_appendlong(notell, velocity, 0, WHITENULL_llll);
                    //// if (mxmlFindElement(itemXML, itemXML, "tie", "type", "start", MXML_DESCEND_FIRST))
                        //// llll_appendlong(notell, 1, 0, WHITENULL_llll);
                    //// else
                        //// llll_appendlong(notell, 0, 0, WHITENULL_llll);
                    
                    bool tie = mxmlFindElement(itemXML, itemXML, "tie", "type", "start", MXML_DESCEND_FIRST) != nullptr;

                    theScore.addNote(pch, velocity, tie);
                    
                    //// t_llll *slotsll = llll_get();
                    //// llll_appendsym(slotsll, gensym("slots"));
                    
                    if (noteheadslot > 0) {
                        mxml_node_t *noteheadXML = mxmlFindElement(itemXML, itemXML, "notehead", NULL, NULL, MXML_DESCEND_FIRST);
                        if (noteheadXML) {
                            const char *notehead_txt = mxmlGetText(noteheadXML, NULL);
                            if (notehead_txt) {
                                long noteheadID = -1;
                                if (!strcmp(notehead_txt, "x"))
                                    noteheadID = k_NOTEHEAD_CROSS;
                                else if (!strcmp(notehead_txt, "diamond"))
                                    noteheadID = k_NOTEHEAD_DIAMOND;
                                else if (!strcmp(notehead_txt, "cross"))
                                    noteheadID = k_NOTEHEAD_PLUS;
                                else if (!strcmp(notehead_txt, "normal")) {
                                    xmlwrite_notehead_manage_filled(itemXML, noteheadXML, k_NOTEHEAD_BLACK_NOTE, k_NOTEHEAD_WHITE_NOTE, k_NOTEHEAD_DEFAULT);
                                } else if (!strcmp(notehead_txt, "square")) {
                                    xmlwrite_notehead_manage_filled(itemXML, noteheadXML, k_NOTEHEAD_BLACK_SQUARE, k_NOTEHEAD_WHITE_SQUARE, k_NOTEHEAD_SQUARE);
                                } else if (!strcmp(notehead_txt, "triangle")) {
                                    xmlwrite_notehead_manage_filled(itemXML, noteheadXML, k_NOTEHEAD_BLACK_TRIANGLE, k_NOTEHEAD_WHITE_TRIANGLE, k_NOTEHEAD_TRIANGLE);
                                }
                                if (noteheadID > 0) {
                                    t_llll *noteheadll = llll_get();
                                    //// llll_appendlong(noteheadll, noteheadslot);
                                    llll_appendsym(noteheadll, notehead_id2symbol(&x->r_ob.noteheads_typo_preferences, noteheadID));
                                    //// llll_appendllll(slotsll, noteheadll);
                                    theScore.addNoteSlot(noteheadslot, noteheadll);
                                }
                            }
                        }
                    }
                    
                    if (articulationsslot > 0) {
                        t_llll *articulationsll = score_parse_articulations_to_llll(x, notationsXML, articulationsslot);
                        if (articulationsll) {
                            //// llll_appendllll(slotsll, articulationsll);
                            theScore.addNoteSlot(articulationsslot, articulationsll);
                        }
                    }
                    
                    //// if (dynamicsslot > 0 && dynamics_text[0]) {
                        //// t_llll *dynamicsll = llll_get();
                        //// llll_appendlong(dynamicsll, dynamicsslot);
                        //// llll_appendsym(dynamicsll, gensym(dynamics_text));
                        //// llll_appendllll(slotsll, dynamicsll);
                    //// }
                    
                    //// if (directionsslot > 0 && words && words->l_size) {
                        //// llll_prependlong(words, directionsslot);
                        //// llll_appendllll(slotsll, words);
                        //// words = NULL;
                    //// }
                
                
                
                
                    if (lyricsslot > 0) {
                        mxml_node_t *lyricXML = mxmlFindElement(itemXML, itemXML, "lyric", NULL, NULL, MXML_DESCEND_FIRST);
                        if (lyricXML) {
                            t_llll *lyricsll = llll_get();
                            mxml_node_t *textXML = mxmlFindElement(lyricXML, lyricXML, "text", NULL, NULL, MXML_DESCEND_FIRST);
                            mxml_node_t *syllabicXML = mxmlFindElement(lyricXML, lyricXML, "syllabic", NULL, NULL, MXML_DESCEND_FIRST);
                            //// llll_appendlong(lyricsll, lyricsslot);
                            const char *txt = textXML ? mxmlGetText(textXML, NULL) : NULL;
                            const char *syllabictxt = syllabicXML ? mxmlGetText(syllabicXML, NULL) : NULL;
                            t_symbol *txtsym = _llllobj_sym_empty_symbol;
                            if (syllabictxt && (!strcmp(syllabictxt, "begin") || !strcmp(syllabictxt, "middle"))) {
                                if (txt) {
                                    long len = strlen(txt);
                                    char *temp_txt = (char *)bach_newptr((len + 2) * sizeof(char));
                                    snprintf_zero(temp_txt, len + 2, "%s-", txt);
                                    txtsym = gensym(temp_txt);
                                    bach_freeptr(temp_txt);
                                } else {
                                    txtsym = gensym("-");
                                }
                            } else if (txt) {
                                txtsym = gensym(txt);
                            }
                            llll_appendsym(lyricsll, txtsym);
                            //// llll_appendllll(slotsll, lyricsll);
                            theScore.addNoteSlot(lyricsslot, lyricsll);
                        }
                    }
                    
                    //// if (slotsll->l_size <= 1) {
                    ////     llll_free(slotsll);
                    ////     slotsll = nullptr;
                    //// }
                
                    //// if (slotsll->l_size > 1)
                        //// llll_appendllll(notell, slotsll);
                    //// else
                        //// llll_free(slotsll);
                    
                    //// llll_appendlong(notell, 0, 0, WHITENULL_llll); // note flags
                    //// llll_appendllll(chordll, notell, 0, WHITENULL_llll);
                    
                } else { // if it's a rest look for articulations and put them in the chord slot
                    if (articulationsslot > 0) {
                        t_llll *articulationsll = score_parse_articulations_to_llll(x, notationsXML, articulationsslot);
                        if (articulationsll) {
                            //// chordslotsll = llll_get();
                            //// llll_appendsym(chordslotsll, _llllobj_sym_slots);
                            //// llll_appendllll(chordslotsll, articulationsll);
                            theScore.setChordSlot(articulationsslot, articulationsll);
                        }
                    }
                }

            }
                        
            //delete [] allpitches;

            //// //llll_appendlong(chordll, 0, 0, WHITENULL_llll); // chord flags
            //// currentChord = nullptr;
            
            theScore.finalizeChord();
            
            // if there was no valid time signature, make one
            theScore.adjustTimeSignatureIfNeeded();
            
            if (t_llll *barline_ll = xml_get_barline(measureXML);
                barline_ll) {
                theScore.setBarline(barline_ll);
            }
            

            
            //// llll_prependllll(measurell[0], measureinfoll, 0, WHITENULL_llll);
            //// llll_appendlong(measurell[0], 0, 0, WHITENULL_llll); // measure flags
            //// llll_appendllll(voicell[0], measurell[0]);
            
            //// for (long i = 1; i <= voices_for_this_xml_part; i++) {
                //// llll_prependllll_clone(measurell[i], measureinfoll);
               ////  llll_appendlong(measurell[i], 0, 0, WHITENULL_llll); // measure flags
                //// llll_appendllll(voicell[i], measurell[i]);
            //// }
            
            isfirstmeasure = 0;
        }
        
        //// for (long i = 0; i < voices_for_this_xml_part; i++) {
            //// llll_appendlong(voicell[i], 0, 0, WHITENULL_llll); // part flags
            //// llll_appendllll(scorell, voicell[i], 0, WHITENULL_llll);
            //// llll_appendsym(clefsll, clefsym);
            //// llll_appendsym(keysll, keysym);
        //// }
        
        //// llll_free(voicell[voices_for_this_xml_part]);
        //// llll_appendlong(numpartsll, voices_for_this_xml_part); // numparts has been added to scorell at the beginning
        
        //// llll_free(words);
        theScore.finalizePart();
    }
    mxmlDelete(scoreXML);
    
    long tone_division = x->r_ob.tone_division;
    if (tone_division % new_tonedivision != 0) {
        object_warn((t_object *) x, "Changed microtonal division!");
        object_attr_setlong(x, gensym("tonedivision"), lcm(tone_division, 4));
    }
    
    object_attr_setlong(x, gensym("measurenumberoffset"), startfromzero ? -1 : 0);
    
    t_llll *scorell = theScore.getllll();
    
#ifdef SCORE_READXML_POSTLL
    dev_llll_print(scorell, (t_object *) x);
#endif // SCORE_READXML_POSTLL

    return scorell;
}




static const std::unordered_map<std::string, const t_rational> type2figure
{ { "breve", {2, 1} },
    { "long", {4, 1} },
    { "maxima", {8, 1} },
    { "whole", {1, 1} },
    { "half", {1, 2} },
    { "quarter", {1, 4} },
    { "eighth", {1, 8} },
    { "16th", {1, 16} },
    { "32nd", {1, 32} },
    { "64th", {1, 64} },
    { "128th", {1, 128} },
    { "256th", {1, 256} }
};


t_rational xml_name_and_dots_to_value(const char *chordtype, long dots)
{
    //cpost("%s", chordtype);
    try {
        const t_rational f = type2figure.at(chordtype);
        return figure_and_dots_to_figure_sym_duration(f, dots);
    }
    catch(std::exception &e) {
        error("Bad chord type: %s", chordtype);
        return t_rational(0, 1);
    }
}




mxml_type_t xml_load_cb(mxml_node_t *node)
{
    const char *name = mxmlGetElement(node);
    
    if (!strcmp(name, "divisions") ||
        !strcmp(name, "fifths") ||
        !strcmp(name, "beat-type") ||
        !strcmp(name, "line") ||
        !strcmp(name, "duration") ||
        !strcmp(name, "staff") ||
        !strcmp(name, "octave") ||
        !strcmp(name, "display-octave") ||
        !strcmp(name, "actual-notes") ||
        !strcmp(name, "normal-notes") ||
        !strcmp(name, "tuplet-number") ||
        !strcmp(name, "dynamics") ||
        !strcmp(name, "tremolo") ||
        !strcmp(name, "clef-octave-change") ||
        !strcmp(name, "voice") ||
        !strcmp(name, "offset"))
        return MXML_INTEGER;
    else if (!strcmp(name, "alter") ||
             !strcmp(name, "key-alter"))
        return MXML_REAL;
    else if (!strcmp(name, "per-minute"))
        return MXML_TEXT;
    else if (!strcmp(name, "words") ||
             !strcmp(name, "beats"))
        return MXML_OPAQUE;
    else
        return MXML_TEXT;
}



const char *xml_mxl_find_rootfile(char *buffer)
{
    mxml_node_t *containerXML = mxmlLoadString(NULL, (char *) buffer, xml_load_cb);
    mxml_node_t *rootfileXML = mxmlFindElement(containerXML, containerXML, "rootfile", NULL, NULL, MXML_DESCEND);
    const char *filename = mxmlElementGetAttr(rootfileXML, "full-path");
    return filename;
}



