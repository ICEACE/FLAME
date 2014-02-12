# sequence of libmboard installation:
# - download the libmboard and unarchive:
#cd downloadedfolder
# - create libmboard directory:
#mkdir libmbdir
# - configuring for serial and without cunits.
#./configure --prefix=/Users/bulent/Documents/AWorkspace/iceace/libmbdir --disable-parallel --disable-tests
# - compiling:
#make
# - installing:
#make install


# sequence of model compilation and simulation run
cp /Users/bulent/iceace/FLAME/initialization/instances/iceace_model_v2.0.0.xml /Users/bulent/iceace/FLAME/initialization/iceace_model_v2.0.0.xml
cp /Users/bulent/iceace/FLAME/initialization/popfiles/iceace_model_v2.0.0.pop /Users/bulent/iceace/FLAME/initialization/iceace_model_v2.0.0.pop

cp /Users/bulent/iceace/FLAME/initialization/iceace_model_v2.0.0.xml /Users/bulent/iceace/FLAME/outputs/its/0.xml
/Users/bulent/iceace/xparser-0.17.0/xparser model_iceace.xml
cp /Users/bulent/iceace/FLAME/stategraph_colour.dot ./docs/
dot -Tpdf ./stategraph_colour.dot -o ./docs/stategraph_colour.pdf
make LIBMBOARD_DIR=/Users/bulent/Documents/AWorkspace/iceace/libmbdir
./main 65 ./outputs/its/0.xml -f 1 > ./outputs/simulation_stream.txt
/Users/bulent/iceace/FLAME/html/updatewebpage.sh
make vclean

### To run the analysis script:
#Rscript ./outputs/scripts/timeseries.R

### to get back to a branch:
#git checkout -b newbranch
#git checkout master
#git merge newbranch
#git branch -d newbranch

# to pull changes made on remote repo:
# git pull

### to rename a file:
#mv oldname newname
#git add newname
#git rm oldname

### to run specific commands:
#cat compile_simulation_model.sh|grep xparser|sh
#cat compile_simulation_model.sh|grep LIBM |sh
#cat compile_simulation_model.sh|grep main|sh
