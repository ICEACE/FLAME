# Run Doxygen GUI to generate the documentation output
# doxygen ./docs/Doxyfile :to generate doxy docs
# git checkout -f gh-pages  :to get rid of all local changes.
# current directory is: gh-page branch, i.e., /Users/bulent/Documents/workspace/iceace/FLAME/html
cd /Users/bulent/Documents/AWorkspace/iceace/FLAME/html

git rm  ./doxy/*.map
git rm  ./doxy/*.md5
git rm  ./doxy/*.png
git rm  ./doxy/*.html
git rm  ./doxy/*.pdf
git rm  ./doxy/*.js
git rm  ./doxy/*.css
git rm  ./doxy/*

echo "Files remained under ./doxy/ :"
ls ./doxy

git commit -a -m "Removing old code documentation related files."
git push origin gh-pages


mv -f ../docs/html/*.map ./doxy/
mv -f ../docs/html/*.md5 ./doxy/
mv -f ../docs/html/*.png ./doxy/
mv -f ../docs/html/*.html ./doxy/
mv -f ../docs/html/*.js ./doxy/
mv -f ../docs/html/*.css ./doxy/
mv -f ../docs/html/* ./doxy/


# For new files:
git add ./doxy/*.map
git commit -m "Design documents are updated, reflecting the integrated implementation."
git push origin gh-pages

git add ./doxy/*.md5
git commit -m "Design documents are updated, reflecting the integrated implementation."
git push origin gh-pages

git add ./doxy/*.png
git commit -m "Design documents are updated, reflecting the integrated implementation."
git push origin gh-pages

git add ./doxy/*.html
git commit -m "Design documents are updated, reflecting the integrated implementation."
git push origin gh-pages

git add ./doxy/*.js
git commit -m "Design documents are updated, reflecting the integrated implementation."
git push origin gh-pages

git add ./doxy/*
git commit -m "Design documents are updated, reflecting the integrated implementation."
git push origin gh-pages

git add ./doxy/*.map
git commit -m "Design documents are updated, reflecting the integrated implementation."
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
git commit -a -m "Adding state graph pdf files."
git push origin gh-pages

sed 's|Author names to add|Bulent Ozel - bulent.ozel@gmail.com|' ./latex.tex > ./newlatex.tex
mv ../newlatex.tex ../latex.tex
#do twice for the table of contents.
pdflatex ../latex.tex
pdflatex ../latex.tex
mv latex.pdf ./doxy/summary.pdf
rm latex.*
git add ./doxy/*.pdf
git commit -a -m "Adding model manual file."
git push origin gh-pages

cp ./doxy/stategraph.pdf ../docs/
cp ./doxy/stategraph_colour.pdf ../docs/
cp ./doxy/summary.pdf ../docs/
cp ./doxy/process_order_graph.pdf ../docs/
cd ..
git commit -a -m "Design documents are updated, reflecting a newer implementation."
git push origin master

cd ./html