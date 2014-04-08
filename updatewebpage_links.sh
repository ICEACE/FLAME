cd /Users/bulent/Documents/AWorkspace/iceace/FLAME/html

# update Web page links.

# when following does not work do it manually for the time being.
sed 's|<tr id="row_0_" class="even"><td class="entry"><img src="ftv2lastnode.png" alt="\" width="16" height="22" /><a class="el" href="md__r_e_a_d_m_e.html" target="_self"></a></td><td class="desc"></td></tr>
|<tr id="row_0_" class="even"><td class="entry"><img src="ftv2lastnode.png" alt="\" width="16" height="22" /><a class="el" href="md__r_e_a_d_m_e.html" target="_self">Readme</a></td><td class="desc">FLAME Implementation README Files</td></tr>
<tr id="row_1_" class="even"><td class="entry"><img src="ftv2lastnode.png" alt="\" width="16" height="22" /><a class="el" href="summary.pdf" target="_self">ICEACE Reference Manual</a></td><td class="desc">PDF summary of implementation.</td></tr>
<tr id="row_3_" class="even"><td class="entry"><img src="ftv2lastnode.png" alt="\" width="16" height="22" /><a class="el" href="stategraph_colour.pdf" target="_self">Overall State Transition Graph</a></td><td class="desc">Detailed agent behaviours and message exchanges.</td></tr>|'
./doxy/pages.html > ./doxy/newpages.html
mv newpages.html pages.html

git commit -a -m "Links to pdf documentation files are added."
git push origin gh-pages
