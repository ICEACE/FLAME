cd /Users/bulent/Documents/AWorkspace/iceace/FLAME/

# Beta = 0.2 #############
sed 's|<household_budget_constraint>0.30</household_budget_constraint>|<household_budget_constraint>0.20</household_budget_constraint>|' ./outputs/its/iceace_model_v1.0.0.xml >  ./outputs/its/00.xml
sed 's|<collect_household_data>1</collect_household_data>|<collect_household_data>1</collect_household_data>|' ./outputs/its/00.xml >  ./outputs/its/0.xml
rm ./outputs/its/00.xml

sed 's|betaval = "0.30"|betaval = "0.20"|' ./outputs/scripts/singleRunAnals.R > ./outputs/scripts/plot0.R
sed 's|niter = 3600|niter = 3600|' ./outputs/scripts/plot0.R > ./outputs/scripts/plot00.R
sed 's|data_household = 1|data_household = 1|' ./outputs/scripts/plot00.R > ./outputs/scripts/plot.R
rm ./outputs/scripts/plot0.R
rm ./outputs/scripts/plot00.R

./main 3600 ./outputs/its/0.xml -f 3600

rm ./outputs/plots/*.png

Rscript ./outputs/scripts/plot.R
rm ./outputs/plots/0.20/*.png
mv ./outputs/plots/*.png ./outputs/plots/0.20/
rm ./outputs/scripts/plot.R

rm ./outputs/data/0.20/*.txt
mv ./outputs/data/*.txt ./outputs/data/0.20/

#git add ./outputs/plots/0.20/*.png
#git commit -a -m "Adding plots for beta = 0.2"
#git push origin master


# Beta = 0.25 #############
sed 's|<household_budget_constraint>0.30</household_budget_constraint>|<household_budget_constraint>0.25</household_budget_constraint>|' ./outputs/its/iceace_model_v1.0.0.xml >  ./outputs/its/00.xml
sed 's|<collect_household_data>1</collect_household_data>|<collect_household_data>1</collect_household_data>|' ./outputs/its/00.xml >  ./outputs/its/0.xml
rm ./outputs/its/00.xml

sed 's|betaval = "0.30"|betaval = "0.25"|' ./outputs/scripts/singleRunAnals.R > ./outputs/scripts/plot0.R
sed 's|niter = 3600|niter = 3600|' ./outputs/scripts/plot0.R > ./outputs/scripts/plot00.R
sed 's|data_household = 1|data_household = 1|' ./outputs/scripts/plot00.R > ./outputs/scripts/plot.R
rm ./outputs/scripts/plot0.R
rm ./outputs/scripts/plot00.R

./main 3600 ./outputs/its/0.xml -f 3600


Rscript ./outputs/scripts/plot.R
rm ./outputs/plots/0.25/*.png
mv ./outputs/plots/*.png ./outputs/plots/0.25/
rm ./outputs/scripts/plot.R

rm ./outputs/data/0.25/*.txt
mv ./outputs/data/*.txt ./outputs/data/0.25/

#git add ./outputs/plots/0.25/*.png
#git commit -a -m "Adding plots for beta = 0.25"
#git push origin master


# Beta = 0.4 #############
sed 's|<household_budget_constraint>0.30</household_budget_constraint>|<household_budget_constraint>0.40</household_budget_constraint>|' ./outputs/its/iceace_model_v1.0.0.xml >  ./outputs/its/00.xml
sed 's|<collect_household_data>1</collect_household_data>|<collect_household_data>1</collect_household_data>|' ./outputs/its/00.xml >  ./outputs/its/0.xml
rm ./outputs/its/00.xml

sed 's|betaval = "0.30"|betaval = "0.40"|' ./outputs/scripts/singleRunAnals.R > ./outputs/scripts/plot0.R
sed 's|niter = 3600|niter = 3600|' ./outputs/scripts/plot0.R > ./outputs/scripts/plot00.R
sed 's|data_household = 1|data_household = 1|' ./outputs/scripts/plot00.R > ./outputs/scripts/plot.R
rm ./outputs/scripts/plot0.R
rm ./outputs/scripts/plot00.R

./main 3600 ./outputs/its/0.xml -f 3600


Rscript ./outputs/scripts/plot.R
rm ./outputs/plots/0.40/*.png
mv ./outputs/plots/*.png ./outputs/plots/0.40/
rm ./outputs/scripts/plot.R

rm ./outputs/data/0.40/*.txt
mv ./outputs/data/*.txt ./outputs/data/0.40/

#git add ./outputs/plots/0.40/*.png
#git commit -a -m "Adding plots for beta = 0.4"
#git push origin master


# Beta = 0.3 #############
sed 's|<household_budget_constraint>0.30</household_budget_constraint>|<household_budget_constraint>0.30</household_budget_constraint>|' ./outputs/its/iceace_model_v1.0.0.xml >  ./outputs/its/00.xml
sed 's|<collect_household_data>1</collect_household_data>|<collect_household_data>1</collect_household_data>|' ./outputs/its/00.xml >  ./outputs/its/0.xml
rm ./outputs/its/00.xml

sed 's|betaval = "0.30"|betaval = "0.30"|' ./outputs/scripts/singleRunAnals.R > ./outputs/scripts/plot0.R
sed 's|niter = 3600|niter = 3600|' ./outputs/scripts/plot0.R > ./outputs/scripts/plot00.R
sed 's|data_household = 1|data_household = 1|' ./outputs/scripts/plot00.R > ./outputs/scripts/plot.R
rm ./outputs/scripts/plot0.R
rm ./outputs/scripts/plot00.R

./main 3600 ./outputs/its/0.xml -f 3600 


Rscript ./outputs/scripts/plot.R
git add ./outputs/plots/0.30/*
rm ./outputs/plots/0.30/*.png
mv ./outputs/plots/*.png ./outputs/plots/0.30/
rm ./outputs/scripts/plot.R

rm ./outputs/data/0.30/*.txt
mv ./outputs/data/*.txt ./outputs/data/0.30/

#git add ./outputs/plots/0.30/*.png
#git commit -a -m "Adding plots for beta = 0.3"
#git push origin master



# Overall Comparison Analysis ########

sed 's|data_household = 1|data_household = 1|' ./outputs/scripts/betaAnalaysis.R > ./outputs/scripts/plot.R
Rscript ./outputs/scripts/plot.R
rm ./outputs/scripts/plot.R

#git add ./outputs/plots/*.png
#git commit -a -m "Adding overall plots on analyses of Beta effects"
#git push origin master

