bach for Max

- SYSTEM REQUIREMENTS
- HOW TO INSTALL
- HOW TO UNINSTALL
- HOW TO SUPPORT BACH
- WHERE TO START
- ACKNOWLEDGMENTS
- CONTACT


===================================================
SYSTEM REQUIREMENTS
===================================================

Intel-based Mac or Windows computer running Max 7.3.5 or higher.


===================================================
HOW TO INSTALL
===================================================

You should install bach directly from the Max Package Manager.

Alternatively, you can copy the "bach" folder inside the "packages" folder in your Max folder. The Max packages folder is under "Documents/Max 7" (for Max 7) or "Documents/Max 8" (for Max 8).

You can also build bach from its source code. For more information about this, see below.


===================================================
HOW TO UNINSTALL
===================================================

Uninstall from Max Package Manager, or delete the "bach" folder from the "packages" folder.


===================================================
HOW TO SUPPORT BACH
===================================================

You can support the bach project on Patreon, at the page https://www.patreon.com/bachproject

Developing and maintaining the bach project is a huge work, which has been taking significant effort and a good chunk of our time since 2010. Most of the work is on the core system (bach), which is freelance project with no institutional support: we rely on Patreon to try to make it sustainable for us.

If you think that bach is not worth your money, or if you can’t afford to pay anything, that's absolutely ok and you then should not contribute. However, if you think that bach is useful and if you can afford to pay us as little as a cup of coffee per month, then you might want to contribute, because this will help keeping bach alive, maintained, and free for everyone.

What do you get for contributing? As we said, contributions are targeted to keeping bach alive, supported and free. The most important thing you get, we hope, is the warm feeling of being part of a family that makes all of this possible!

All Patrons obtain a code to remove the bach splash screen in their patches for the whole solar year (on the other hand, removing the splash screen from standalones is unfortunately more complicated, and might require particular arrangements).

In addition, Patrons get several benefits: from early access to prereleases, all the way up to private Skype/Google Hangouts meeting for the top tier (passing through a set of exclusive video tutorials and the possibility to submit feature requests).


===================================================
WHERE TO START
===================================================

The patch "bach.overview" (located in the "Extras" Max's menu) contains a detailed documentation of all the global system features (which you should read entirely), and links to the help files of all the externals and abstractions. We have tried to keep all this information in a somewhat pedagogical order, and in principle you are encouraged to run through it from beginning to end to get an idea of the tools you are provided with.

The best thing to do to start learning bach is following the tutorials that you find in the "bach.overview". 
You can also access a series of video tutorials from our Patreon page; for some of the videos Patrons have early access (1 year before anyone else), but you can still access all the other ones, as well as the old patrons-only videos when after 1 year from they creation (also see the Patreon section above).

The only prerequisite to bach is a solid (but not necessarily hyper-advanced) knowledge of Max. The documentation will sometimes hint at advanced topics, such as threading, but if you don't feel at ease with them you can simply overlook them.

Of course, experimentation is always the core of understanding. As soon as you get the very first notions, the best you can do is start patching. Just remember that this is a beta release: save your patches and data as often as you can - we can't assure you that Max won't hang or crash as soon as you click that button you just added!


===================================================
BUILDING FROM SOURCE
===================================================

As bach is an open source project as of v0.8.1, it is possible to download its complete source code and build the library from it.
The source code of bach is hosted on Github, at the URL
The repository is identical to the bach Max package, except that it does not contain the binaries (which you are supposed to be willing to build if you download it), but it contains a "source" folder with all the source code, third-party dependencies included (see below), except the Max SDK. You should install the bach folder downloaded from Github, or clone the repository, directly in your Max packages folder, instead of the bach package from the Package Manager.

On a Mac, you need the following tools for building bach:
- Xcode (version 9.4 or higher)
- The Max SDK (version 7.3.3 or higher: the provided Xcode project looks for version 7.3.3, but it should not be difficult to upgrade it for a higher version), installed in the Max packages folder.
- Flex (version 2.6.0 or higher) and Bison (version 2.3 or higher). Notice that you need to install manually Flex and Bison, as the versions provided with Xcode are not compatible with the grammars included in bach.
The provided makefiles look for the correct versions of Flex and Bison respectively in /usr/local/opt/bison/bin and /usr/local/opt/flex/bin, which should be where brew installs them. You may want to make sure of that though, and possibly fix manually the makefiles. A cleaner way might actually be including a configure script in the distribution.

On Windows, you only need Visual Studio 2017 or higher.

bach contains a number of Flex / Bison lexers and parsers tackling the llll textual representation, bach.expr expressions and bell programs. The bach repository contains both the Flex / Bison grammar files (.l and .y), with the makefiles invoking Flex and Bison, and the C code files they produce. This is somewhat unorthodox, but necessary because currently Flex and Bison are only invoked when bach is built on a Mac, whereas on Windows the .l, .y and makefiles are ignored, and bach is only built from the C code files. So, if you are a Windows user and you want to modify the grammars, you have to either find a compatible Flex / Bison distribution for Windows, install it and run it on your machine (and, why not, share some information about it with the bach dev community and us), or generate the lexers and parsers on a UNIX machine and transfer them to Windows. If you don't want to fiddle with the grammars instead, you can avoid installing Flex and Bison on a Mac as well, and modify the makefiles or the relevant build targets so as not to invoke them when the project is built (and perhaps adding an exclude file to your local repository, so that these customizations are preserved whenever you pull from the remote).

===================================================
DEPENDENCIES
===================================================

bach includes:
- Robert Piéchaud's "November for bach" font, a customized version of the "November" font (https://www.klemm-music.de/notation/november2/en/index.php)
- A modified version of Simon Tatham's listsort (https://www.chiark.greenend.org.uk/~sgtatham/algorithms/listsort.c)
- A modified version of The Mini-XML library (https://www.msweet.org/mxml/index.html)
- A modified version of the Kiss FFT library (https://github.com/mborgerding/kissfft)
- A modified version of the IRCAM SDIF library (http://sdif.sourceforge.net/extern/alpha-main.html)

All the above modules are included in the publicly available source code repository of bach.


===================================================
ACKNOWLEDGMENTS
===================================================

This project has been partially undertaken during the permanence of the authors at IRCAM, first as students at the Cursus in Composition and Musical Informatics and then as composers in research.

The bell programming language has been conceived and developed by Andrea Agostini within the context of a MRC residency at IRCAM, under the supervision of Jean Louis Giavitto.

We wish to thank Carlos Agon, Gérard Assayag, Greg Beller, Arshia Cont, Emmanuel Jourdan, Serge Lemouton, Jean Lochard, Mikhail Malt and all the other people at IRCAM who have supported and encouraged the work, although not an internal IRCAM project. We would like to especially acknowledge the friendship of the late ƒric Daubresse, one of the earliest and most enthousiastic supporters of bach.

We also wish to thank Cycling '74 for their help with allowing bach do the obscure things it does inside Max, in particular Jeremy Bernstein, Joshua Kit Clayton, Emmanuel Jourdan (once again!), Andrew Pask, Gregory Taylor and David Zicarelli.

A special thanks goes to Robert Piéchaud, for giving us a customized, open-source version of his beautiful "November" music font for inclusion in bach.

Finally, we wish to thank all our Patreon supporters, whose generous contribution is a tangible encouragement to carry on our quixotic work.


===================================================
CONTACT
===================================================

To contact us send a mail to info@bachproject.net.

For bug report and discussions, you can also use the forum of our website: www.bachproject.net.

