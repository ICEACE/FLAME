cd /Users/bulent/Documents/workspace/iceace/FLAME/html

rm -r ./doxy/*
mv -f ../docs/html/* ./doxy
# For new files:
git add ./doxy/*

# If only updated pages to be comitted:
# git commit -a -m "Web page design is updated."
git commit -m "Design documents are updated, reflecting a newer implementation."
git push origin gh-pages

# Linking doxy site to github pages.
sed 's|ICEACE Documentation|<a href="http://iceace.github.com/FLAME/"> Click this link to access main site of ICEACE. <p>The site provides general information and points to software downloads on FLAME implementation.</p></a>|' ./doxy/index.html > ./doxy/newindex.html
mv ./doxy/newindex.html ./doxy/index.html
git commit -a -m "Design documents are updated, reflecting a newer implementation."
git push origin gh-pages


# Insertion of pdf and state diagrams:
#
dot -Tpdf ../stategraph.dot -o ./doxy/stategraph.pdf
dot -Tpdf ../stategraph_colour.dot -o ./doxy/stategraph_colour.pdf
dot -Tpdf ../process_order_graph.dot -o ./doxy/process_order_graph.pdf

sed 's|Author names to add|Bulent Ozel - bulent.ozel@gmail.com|' ../latex.tex > ../newlatex.tex
mv ../newlatex.tex ../latex.tex
#do twice for the table of contents.
pdflatex ../latex.tex
pdflatex ../latex.tex
mv latex.pdf ./doxy/summary.pdf
rm latex.*
git add ./doxy/*.pdf
git commit -a -m "Design documents are updated, reflecting a newer implementation."
git push origin gh-pages

cp ./doxy/stategraph.pdf ../docs/
cp ./doxy/stategraph_colour.pdf ../docs/
cp ./doxy/summary.pdf ../docs/
cp ./doxy/process_order_graph.pdf ../docs/
cd ..
git commit -a -m "Design documents are updated, reflecting a newer implementation."
git push origin master