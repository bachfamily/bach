inlets = 1;
outlets = 0;

var howMany = 1;

var allPatches = [];

var allObjects = [

["bach.append", ""],
["bach.classify", ""],
["bach.collect", ""],
["bach.contains", ""],
["bach.decode", ""],
["bach.defer", ""],
["bach.deferlow", ""],
["bach.delace", ""],
["bach.depth", ""],
["bach.dict2llll", ""],
["bach.encode", ""],
["bach.find", ""],
["bach.flat", ""],
["bach.group", ""],
["bach.insert", ""],
["bach.is", ""],
["bach.iter", ""],
["bach.join", ""],
["bach.keys", ""],
["bach.lace", ""],
["bach.length", ""],
["bach.llll2dict", ""],
["bach.mapelem", ""],
["bach.mdelace", ""],
["bach.minmax", ""],
["bach.msort", ""],
["bach.pack", "foo"],
["bach.pad", ""],
["bach.pick", 1],
["bach.pipe", ""],
["bach.portal", ""],
["bach.post", ""],
["bach.print", ""],
["bach.pv", "foo"],
["bach.ratnum", ""],
["bach.reg", ""],
["bach.rot", ""],
["bach.shelf", ""],
["bach.sort", ""],
["bach.ssort", ""],
["bach.step", ""],
["bach.tree", ""],
["bach.textin", ""],
["bach.textout", ""],
["bach.reshape", ""],
["bach.rev", ""],
["bach.slice", ""],
["bach.subs", ""],
["bach.swap", ""],
["bach.thin", ""],
["bach.trans", ""],
["bach.value", "foo"],



["bach.==", ""], 
["bach.>=", ""], 
["bach.>", ""], 
["bach.<=", ""], 
["bach.<", ""], 
["bach.!=", ""],



["bach.cartesianprod", ""], 
["bach.comb", ""], 
["bach.constraints", ""], 
["bach.oneperm", ""], 
["bach.perm", ""], 
["bach.poset", ""], 
["bach.partition", ""], 
["bach.scramble", ""],



["bach.diff", ""], 
["bach.intersection", ""], 
["bach.symdiff", ""], 
["bach.union", ""], 



["bach.arithmser", ""], 
["bach.derive", ""], 
["bach.expr", ""], 
["bach.factorize", ""], 
["bach.float2rat", ""], 
["bach.fft", ""], 
["bach.geomser", ""], 
["bach.graph", ""], 
["bach.integrate", ""], 
["bach.prime", ""], 
["bach.primeser", ""], 
["bach.resample", ""], 
["bach.recurser", ""], 
["bach.weights", ""], 

["bach.bachtree2omtree", ""], 
["bach.beatbox", ""], 
["bach.beatunbox", ""], 
["bach.circle", ""], 
["bach.ivec", ""], 
["bach.mc2n", ""], 
["bach.mc2p", ""], 
["bach.omtree2bachtree", ""], 
["bach.n2mc", ""], 
["bach.p2mc", ""], 
["bach.primeform", ""], 
["bach.playkeys", "cents"], 
["bach.quantize", ""], 
["bach.tonnetz", ""], 
["bach.transcribe", ""], 

["bach.roll", ""], 

["bach.score", ""], 

["bach.reducefunction", ""], 
["bach.slot", ""], 

["bach.adj", ""], 
["bach.convertbase", ""], 
["bach.diag", ""], 
["bach.eig", ""], 
["bach.extractbasis", ""], 
["bach.gausselim", ""], 
["bach.linearsolve", ""], 
["bach.minfo", ""], 
["bach.mtimes", ""], 
["bach.submatrix", ""], 
["bach.trace", ""], 
["bach.zsearch", ""], 

["bach.read", ""], 
["bach.readsdif", ""], 
["bach.write", ""], 
["bach.writesdif", ""], 

["bach.eval", ""], 

["bach.args", ""], 
["bach.hypercomment", ""], 
["bach.wordcloud", ""], 

];

function createOne(value, index, array) {
	myPatch = new Patcher(0, 0, 500, 500);
	myPatch.message("front");
	myPatch.message("title", value[0]);
	allPatches.push(myPatch);
	for (i = 0; i < howMany; i++) {
		var obj = myPatch.newdefault(0, i*20, value[0], value[1]);
		//myPatch.remove(obj);
	}
		
	post("creating " + value[0] + "\n");
}

function copies(c) {
	howMany = c;
}

function destroyPatch(value, index, array) {
	value.message("dispose");
}

function bang()
{
	//myPatch.newdefault(0, 0, "metro");
	allObjects.forEach(createOne);
	this.patcher.message("front");
}

function closeall()
{
	allPatches.forEach(destroyPatch);
}