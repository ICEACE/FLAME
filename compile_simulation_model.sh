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
../xparser-0.17.0/xparser model_v0.1.0.xml
make LIBMBOARD_DIR=/Users/bulent/Documents/AWorkspace/iceace/libmbdir
./main 245 ./outputs/0.xml -f 1 > ./outputs/simulation_stream.txt
../html/updatewebpage.sh
make vclean

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

