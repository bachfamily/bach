// tzeropage.js

function InsertSampleMovie(filename)
{
    document.write('<object classid="clsid: 02BF25D5-8C17-4B23-BC80-D3488ABDDC6B" width="650" height="500" codebase="http://www.apple.com/qtactivex/qtplugin.cab">\n');
    document.write('<param name="src" value="' + filename + '" />\n');
    document.write('<param name="autoplay" value="true" />\n');
    document.write('<param name="controller" value="true" />\n');
    document.write('<param name="loop" value="false" />\n');
    document.write('<embed src="' + filename + '" width="650" height="500" autoplay="true" controller="true" loop="false" pluginspage="http://www.apple.com/quicktime/download/" />')
    document.write('</object>\n');
}
