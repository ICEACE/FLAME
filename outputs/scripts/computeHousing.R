file = paste(data_dir, '/', "REAgency_sales.txt", sep ='')
housing <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
nMonths = length(housing$IT_NO)
fireA <- housing$HHFireA
regA <- housing$HHRegularA
firmA <- housing$FirmA

fireS <- housing$HHFireS
regS <- housing$HHRegularS
firmS <- housing$FirmS

plot_time_series_point_file(nMonths, fireS, "Months", "Frequencies", "Fire Sales by Households", "aHousingFireSales.png", ltype = "h", ispoint = T)

plot_time_series_point_file(nMonths, regS, "Months", "Frequencies", "Regular Sales by Household", "aHousingRegularSales.png", ltype = "h", ispoint = T)

plot_time_series_point_file(nMonths, firmS, "Months", "Frequencies", "Sales by Constructor Firms", "aHousingFirmSales.png", ltype = "h", ispoint = T)

attempts <- housing[,2] + housing[,3] + housing[,4]
sales <- housing[,5] + housing[,6] + housing[,7]
ratios <- sales / attempts

plot_time_series_point_file(nMonths, ratios, "Months", "Ratio", "Ratio of Housing Units Sold at the Market", "aHousingRatios.png", isgrid = T, ltype = "l", ispoint = T)