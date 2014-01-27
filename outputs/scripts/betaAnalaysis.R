### Init Workspace  ###
rm(list = ls())
source("/Users/bulent/Documents/AWorkspace/iceace/FLAME/outputs/scripts/LibIceace.R", echo = TRUE)
data_dir = "/Users/bulent/Documents/AWorkspace/iceace/FLAME/outputs/data"
output_dir = "/Users/bulent/Documents/AWorkspace/iceace/FLAME/outputs/plots/"
setwd(output_dir)

# Unemployment Rates:

file = paste(data_dir, '/0.20/', "Government_snapshot.txt", sep ='')
Government0.20 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
file = paste(data_dir, '/0.25/', "Government_snapshot.txt", sep ='')
Government0.25 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
file = paste(data_dir, '/0.30/', "Government_snapshot.txt", sep ='')
Government0.30 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
file = paste(data_dir, '/0.40/', "Government_snapshot.txt", sep ='')
Government0.40 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)

unemployemnt0.40 <- Government0.40$UNEMPLOYMENT_RATE
unemployemnt0.30 <- Government0.30$UNEMPLOYMENT_RATE
unemployemnt0.25 <- Government0.25$UNEMPLOYMENT_RATE
unemployemnt0.20 <- Government0.20$UNEMPLOYMENT_RATE
plot_time_series_multiline_point_file(length(unemployemnt0.20), unemployemnt0.20, unemployemnt0.25, "Quarters", "Rate", "Unemployment Rates", "Unemployment.png", c("beta = 0.20", "beta = 0.25", "beta = 0.30", "beta = 0.40"), v3 = unemployemnt0.30, v4 = unemployemnt0.40, isgrid = T, ispoint = F)

# Wages:
wages0.40 <- Government0.40$AVERAGE_WAGE
wages0.30 <- Government0.30$AVERAGE_WAGE
wages0.25 <- Government0.25$AVERAGE_WAGE
wages0.20 <- Government0.20$AVERAGE_WAGE
plot_time_series_multiline_point_file(length(wages0.20), wages0.20, wages0.25, "Quarters", "Rate", "Average Wages", "Wages.png", c("beta = 0.20", "beta = 0.25", "beta = 0.30", "beta = 0.40"), v3 = wages0.30, v4 = wages0.40, isgrid = T, ispoint = F)


# Government Deficits:
balance0.20 <- Government0.20$EARNINGS - Government0.20$EXPENDITURES
balance0.25 <- Government0.25$EARNINGS - Government0.25$EXPENDITURES
balance0.30 <- Government0.30$EARNINGS - Government0.30$EXPENDITURES
balance0.40 <- Government0.40$EARNINGS - Government0.40$EXPENDITURES
plot_time_series_multiline_point_file(length(balance0.20), balance0.20, balance0.25, "Quarters", "Amount", "Government Deficit (Earnings - Expenditures)", "GovernmentDeficit.png", c("beta = 0.20", "beta = 0.25", "beta = 0.30", "beta = 0.40"), v3 = balance0.30, v4 = balance0.40, isgrid = F, ispoint = F)


# Interest Rates:

file = paste(data_dir, '/0.20/', "CentralBank_snapshot.txt", sep ='')
Centralbank0.20 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
file = paste(data_dir, '/0.25/', "CentralBank_snapshot.txt", sep ='')
Centralbank0.25 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
file = paste(data_dir, '/0.30/', "CentralBank_snapshot.txt", sep ='')
Centralbank0.30 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
file = paste(data_dir, '/0.40/', "CentralBank_snapshot.txt", sep ='')
Centralbank0.40 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)

interestrate0.20 <- Centralbank0.20$INTEREST_RATE
interestrate0.25 <- Centralbank0.25$INTEREST_RATE
interestrate0.30 <- Centralbank0.30$INTEREST_RATE
interestrate0.40 <- Centralbank0.40$INTEREST_RATE
plot_time_series_multiline_point_file(length(interestrate0.20), interestrate0.20, interestrate0.25, "Quarters", "Rate", "Central Bank Interest Rates", "InterestRate.png", c("beta = 0.20", "beta = 0.25", "beta = 0.30", "beta = 0.40"),  v3 = interestrate0.30, v4 = interestrate0.40, isgrid = F, ispoint = F)

# Inflations: 
inflation0.20 <- Centralbank0.20$INFLATION_RATE
inflation0.25 <- Centralbank0.25$INFLATION_RATE
inflation0.30 <- Centralbank0.30$INFLATION_RATE
inflation0.40 <- Centralbank0.40$INFLATION_RATE
plot_time_series_multiline_point_file(length(inflation0.20), inflation0.20, inflation0.25,  "Quarters", "Rate", "Inflation Rates", "Inflation.png", c("beta = 0.20", "beta = 0.25", "beta = 0.30", "beta = 0.40"), v3 = inflation0.30, v4 = inflation0.40, isgrid = F, ispoint = F)


# Goods Prices

file = paste(data_dir, '/0.20/', "Mall_snapshot.txt", sep ='')
Mall0.20 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
file = paste(data_dir, '/0.25/', "Mall_snapshot.txt", sep ='')
Mall0.25 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
file = paste(data_dir, '/0.30/', "Mall_snapshot.txt", sep ='')
Mall0.30<- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
file = paste(data_dir, '/0.40/', "Mall_snapshot.txt", sep ='')
Mall0.40 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)

goodsprices0.20 <- Mall0.20$AVG_GOODS_PRICE
goodsprices0.25 <- Mall0.25$AVG_GOODS_PRICE
goodsprices0.30 <- Mall0.30$AVG_GOODS_PRICE
goodsprices0.40 <- Mall0.40$AVG_GOODS_PRICE
plot_time_series_multiline_point_file(length(goodsprices0.20), goodsprices0.20, goodsprices0.25, "Weeks", "Unit Price", "Average Goods Prices (realized)", "AvgGoodsPrices.png", c("beta = 0.20", "beta = 0.25", "beta = 0.30", "beta = 0.40"), v3 = goodsprices0.30, v4 = goodsprices0.40, isgrid = F, ispoint = F)

# Housing Prices:

file = paste(data_dir, '/0.20/', "REAgency_snapshot.txt", sep ='')
REAgency0.20 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
file = paste(data_dir, '/0.25/', "REAgency_snapshot.txt", sep ='')
REAgency0.25 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
file = paste(data_dir, '/0.30/', "REAgency_snapshot.txt", sep ='')
REAgency0.30 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
file = paste(data_dir, '/0.40/', "REAgency_snapshot.txt", sep ='')
REAgency0.40 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)

# Nominal
nhousingprices0.20 <- REAgency0.20$AVG_HOUSING_PRICE
nhousingprices0.25 <- REAgency0.25$AVG_HOUSING_PRICE
nhousingprices0.30 <- REAgency0.30$AVG_HOUSING_PRICE
nhousingprices0.40 <- REAgency0.40$AVG_HOUSING_PRICE

plot_time_series_multiline_point_file(length(nhousingprices0.20), nhousingprices0.20, nhousingprices0.25,  "Months", "Average Prices", "Average Housing Unit Prices (Nominal)", "AvgHousingPricesNominal.png", c("beta = 0.20", "beta = 0.25", "beta = 0.30", "beta = 0.40"), isgrid = F, ispoint = F, v3 = nhousingprices0.30, v4 = nhousingprices0.40)

# Real -
L <- 1:length(goodsprices0.20)
L <- L %% 4
L <- L == 1
mgoodsprices0.20 <- goodsprices0.20[L]
mgoodsprices0.25 <- goodsprices0.25[L]
mgoodsprices0.30 <- goodsprices0.30[L]
mgoodsprices0.40 <- goodsprices0.40[L]

cpi0.20 <- mgoodsprices0.20 / mgoodsprices0.20[1]
cpi0.25 <- mgoodsprices0.25 / mgoodsprices0.25[1]
cpi0.30 <- mgoodsprices0.30 / mgoodsprices0.30[1]
cpi0.40 <- mgoodsprices0.40 / mgoodsprices0.40[1]

rhousingprices0.20 <- nhousingprices0.20 / cpi0.20
rhousingprices0.25 <- nhousingprices0.25 / cpi0.25
rhousingprices0.30 <- nhousingprices0.30 / cpi0.30
rhousingprices0.40 <- nhousingprices0.40 / cpi0.40


plot_time_series_multiline_point_file(length(rhousingprices0.20), rhousingprices0.20, rhousingprices0.25,  "Months", "Price Indices", "Housing Unit Price Indices", "AvgHousingPricesReal.png", c("beta = 0.20", "beta = 0.25", "beta = 0.30", "beta = 0.40"), v3 = rhousingprices0.30, v4 = rhousingprices0.40, legposn = "bottomright", isgrid = T, ispoint = F)


# Capital Income:
file = paste(data_dir, '/0.20/', "EquityFund_snapshot.txt", sep ='')
Equityfund0.20 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
file = paste(data_dir, '/0.25/', "EquityFund_snapshot.txt", sep ='')
Equityfund0.25 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
file = paste(data_dir, '/0.30/', "EquityFund_snapshot.txt", sep ='')
Equityfund0.30 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
file = paste(data_dir, '/0.40/', "EquityFund_snapshot.txt", sep ='')
Equityfund0.40 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)

dividendspaid0.20 <- Equityfund0.20$DIVIDENDS_PAID
dividendspaid0.25 <- Equityfund0.25$DIVIDENDS_PAID
dividendspaid0.30 <- Equityfund0.30$DIVIDENDS_PAID
dividendspaid0.40 <- Equityfund0.40$DIVIDENDS_PAID

plot_time_series_multiline_point_file(length(dividendspaid0.20), dividendspaid0.20, dividendspaid0.25,  "Quarters", "Amount", "Dividends Paid", "DividendsPaid.png", c("beta = 0.20", "beta = 0.25", "beta = 0.30", "beta = 0.40"), v3 = dividendspaid0.30, v4 = dividendspaid0.40, isgrid = F, ispoint=F)

# Loans:
file = paste(data_dir, '/0.20/', "Bank_BalanceSheet.txt", sep ='')
BankBalance0.20 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
file = paste(data_dir, '/0.25/', "Bank_BalanceSheet.txt", sep ='')
BankBalance0.25 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
file = paste(data_dir, '/0.30/', "Bank_BalanceSheet.txt", sep ='')
BankBalance0.30 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
file = paste(data_dir, '/0.40/', "Bank_BalanceSheet.txt", sep ='')
BankBalance0.40 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)

loans0.20 <- get_aggregate_values(BankBalance0.20$IT_NO, BankBalance0.20$LOANS)
loans0.25 <- get_aggregate_values(BankBalance0.25$IT_NO, BankBalance0.25$LOANS)
loans0.30 <- get_aggregate_values(BankBalance0.30$IT_NO, BankBalance0.30$LOANS)
loans0.40 <- get_aggregate_values(BankBalance0.40$IT_NO, BankBalance0.40$LOANS)

plot_time_series_multiline_point_file(length(loans0.20), loans0.20, loans0.25, "Quarters", "Total Amount", "Loans to Firms", "Loans.png", c("beta = 0.20", "beta = 0.25", "beta = 0.30", "beta = 0.40"), v3 = loans0.30, v4 = loans0.40, isgrid = F, ispoint=F)


# Mortgages:
mortgages0.20 <- get_aggregate_values(BankBalance0.20$IT_NO, BankBalance0.20$MORTGAGES)
mortgages0.25 <- get_aggregate_values(BankBalance0.25$IT_NO, BankBalance0.25$MORTGAGES)
mortgages0.30 <- get_aggregate_values(BankBalance0.30$IT_NO, BankBalance0.30$MORTGAGES)
mortgages0.40 <- get_aggregate_values(BankBalance0.40$IT_NO, BankBalance0.40$MORTGAGES)

plot_time_series_multiline_point_file(length(mortgages0.20), mortgages0.20, mortgages0.25,  "Quarters", "Total Amount", "Mortgages to Households", "Mortgages.png", c("beta = 0.20", "beta = 0.25", "beta = 0.30", "beta = 0.40"), v3 = mortgages0.30, v4 = mortgages0.40, isgrid = F, ispoint=F)

# Private Sector Debt:
privatedebt0.20 <- mortgages0.20 + loans0.20
privatedebt0.25 <- mortgages0.25 + loans0.25
privatedebt0.30 <- mortgages0.30 + loans0.30
privatedebt0.40 <- mortgages0.40 + loans0.40

plot_time_series_multiline_point_file(length(privatedebt0.20), privatedebt0.20, privatedebt0.25,  "Quarters", "Total Amount", "Private Sector Debt", "PrivateSectorDebt.png", c("beta = 0.20", "beta = 0.25", "beta = 0.30", "beta = 0.40"), v3 = privatedebt0.30, v4 = privatedebt0.40, isgrid = F, ispoint=F)

#GDP Nominal:
nMonths <- length(Government0.20$IT_NO) * 3

# 0.20: 
file = paste(data_dir, '/0.20/', "Firm_Monthly.txt", sep ='')
FirmMonthly0.20 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
file = paste(data_dir, '/0.20/', "Constructor_Firm_Monthly.txt", sep ='')
CFirmMonthly0.20 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)

FirmMonthly0.20$Nominal <- FirmMonthly0.20$PRODUCTION_CURRENT * FirmMonthly0.20$UNIT_GOODS_PRICE
FirmMonthly0.20$Real <- FirmMonthly0.20$PRODUCTION_CURRENT * FirmMonthly0.20$UNIT_GOODS_PRICE[1]

CFirmMonthly0.20$Nominal <- CFirmMonthly0.20$PRODUCTION_CURRENT * CFirmMonthly0.20$UNIT_HOUSE_PRICE
CFirmMonthly0.20$Real <- CFirmMonthly0.20$PRODUCTION_CURRENT * CFirmMonthly0.20$UNIT_HOUSE_PRICE[1]

gdpnominal0.20 <- get_aggregate_values_v2(FirmMonthly0.20$IT_NO, FirmMonthly0.20$Nominal, nMonths) + get_aggregate_values_v2(CFirmMonthly0.20$IT_NO, CFirmMonthly0.20$Nominal, nMonths)
gdpreal0.20 <- get_aggregate_values_v2(FirmMonthly0.20$IT_NO, FirmMonthly0.20$Real, nMonths) + get_aggregate_values_v2(CFirmMonthly0.20$IT_NO, CFirmMonthly0.20$Real, nMonths)


#0.25:

file = paste(data_dir, '/0.25/', "Firm_Monthly.txt", sep ='')
FirmMonthly0.25 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
file = paste(data_dir, '/0.25/', "Constructor_Firm_Monthly.txt", sep ='')
CFirmMonthly0.25 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)

FirmMonthly0.25$Nominal <- FirmMonthly0.25$PRODUCTION_CURRENT * FirmMonthly0.25$UNIT_GOODS_PRICE
FirmMonthly0.25$Real <- FirmMonthly0.25$PRODUCTION_CURRENT * FirmMonthly0.25$UNIT_GOODS_PRICE[1]

CFirmMonthly0.25$Nominal <- CFirmMonthly0.25$PRODUCTION_CURRENT * CFirmMonthly0.25$UNIT_HOUSE_PRICE
CFirmMonthly0.25$Real <- CFirmMonthly0.25$PRODUCTION_CURRENT * CFirmMonthly0.25$UNIT_HOUSE_PRICE[1]

gdpnominal0.25 <- get_aggregate_values_v2(FirmMonthly0.25$IT_NO, FirmMonthly0.25$Nominal, nMonths) + get_aggregate_values_v2(CFirmMonthly0.25$IT_NO, CFirmMonthly0.25$Nominal, nMonths)
gdpreal0.25 <- get_aggregate_values_v2(FirmMonthly0.25$IT_NO, FirmMonthly0.25$Real, nMonths) + get_aggregate_values_v2(CFirmMonthly0.25$IT_NO, CFirmMonthly0.25$Real, nMonths)

#0.30:
file = paste(data_dir, '/0.30/', "Firm_Monthly.txt", sep ='')
FirmMonthly0.30 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
file = paste(data_dir, '/0.30/', "Constructor_Firm_Monthly.txt", sep ='')
CFirmMonthly0.30 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)

FirmMonthly0.30$Nominal <- FirmMonthly0.30$PRODUCTION_CURRENT * FirmMonthly0.30$UNIT_GOODS_PRICE
FirmMonthly0.30$Real <- FirmMonthly0.30$PRODUCTION_CURRENT * FirmMonthly0.30$UNIT_GOODS_PRICE[1]

CFirmMonthly0.30$Nominal <- CFirmMonthly0.30$PRODUCTION_CURRENT * CFirmMonthly0.30$UNIT_HOUSE_PRICE
CFirmMonthly0.30$Real <- CFirmMonthly0.30$PRODUCTION_CURRENT * CFirmMonthly0.30$UNIT_HOUSE_PRICE[1]

gdpnominal0.30 <- get_aggregate_values_v2(FirmMonthly0.30$IT_NO, FirmMonthly0.30$Nominal, nMonths) + get_aggregate_values_v2(CFirmMonthly0.30$IT_NO, CFirmMonthly0.30$Nominal, nMonths)
gdpreal0.30 <- get_aggregate_values_v2(FirmMonthly0.30$IT_NO, FirmMonthly0.30$Real, nMonths) + get_aggregate_values_v2(CFirmMonthly0.30$IT_NO, CFirmMonthly0.30$Real, nMonths)

#0.40:
file = paste(data_dir, '/0.40/', "Firm_Monthly.txt", sep ='')
FirmMonthly0.40 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
file = paste(data_dir, '/0.40/', "Constructor_Firm_Monthly.txt", sep ='')
CFirmMonthly0.40 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)

FirmMonthly0.40$Nominal <- FirmMonthly0.40$PRODUCTION_CURRENT * FirmMonthly0.40$UNIT_GOODS_PRICE
FirmMonthly0.40$Real <- FirmMonthly0.40$PRODUCTION_CURRENT * FirmMonthly0.40$UNIT_GOODS_PRICE[1]

CFirmMonthly0.40$Nominal <- CFirmMonthly0.40$PRODUCTION_CURRENT * CFirmMonthly0.40$UNIT_HOUSE_PRICE
CFirmMonthly0.40$Real <- CFirmMonthly0.40$PRODUCTION_CURRENT * CFirmMonthly0.40$UNIT_HOUSE_PRICE[1]

gdpnominal0.40 <- get_aggregate_values_v2(FirmMonthly0.40$IT_NO, FirmMonthly0.40$Nominal, nMonths) + get_aggregate_values_v2(CFirmMonthly0.40$IT_NO, CFirmMonthly0.40$Nominal, nMonths)
gdpreal0.40 <- get_aggregate_values_v2(FirmMonthly0.40$IT_NO, FirmMonthly0.40$Real, nMonths) + get_aggregate_values_v2(CFirmMonthly0.40$IT_NO, CFirmMonthly0.40$Real, nMonths)

plot_time_series_multiline_point_file(length(gdpnominal0.20), gdpnominal0.20, gdpnominal0.25, "Months", "Total Goods and Housing Units", "GDP - Nominal", "GDP_Nominal.png", c("beta = 0.20", "beta = 0.25", "beta = 0.30", "beta = 0.40"), v3 = gdpnominal0.30, v4 = gdpnominal0.40, isgrid = F, ispoint=F)

plot_time_series_multiline_point_file(length(gdpreal0.20), gdpreal0.20, gdpreal0.25, "Months", "Total Goods and Housing Units", "GDP - Real", "GDP_Real.png", c("beta = 0.20", "beta = 0.25", "beta = 0.30", "beta = 0.40"), v3 = gdpreal0.30, v4 = gdpreal0.40, isgrid = F, ispoint=F)


data_household = 1

if (data_household){
	file = paste(data_dir, '/0.20/', "Household_Quarterly.txt", sep ='')
	Household0.20 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
	file = paste(data_dir, '/0.25/', "Household_Quarterly.txt", sep ='')
	Household0.25 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
	file = paste(data_dir, '/0.30/', "Household_Quarterly.txt", sep ='')
	Household0.30 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
	file = paste(data_dir, '/0.40/', "Household_Quarterly.txt", sep ='')
	Household0.40 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
	
	nQuarters <- length(Centralbank0.20$IT_NO)
	nHouseholds <- length(Household0.20$IT_NO)/nQuarters

    # Housing Payment:
	housingpayment0.20 <- get_means(nHouseholds, nQuarters, Household0.20$HOUSING_PAYMENT)
	housingpayment0.25 <- get_means(nHouseholds, nQuarters, Household0.25$HOUSING_PAYMENT)
	housingpayment0.30 <- get_means(nHouseholds, nQuarters, Household0.30$HOUSING_PAYMENT)
	housingpayment0.40 <- get_means(nHouseholds, nQuarters, Household0.40$HOUSING_PAYMENT)
	
	plot_time_series_multiline_point_file(length(housingpayment0.20), housingpayment0.20, housingpayment0.25,  "Quarters", "Mean Housing Payments", "Households's Mean Housing Payments", "HousingPayment.png", c("beta = 0.20", "beta = 0.25", "beta = 0.30", "beta = 0.40"), v3 = housingpayment0.30, v4 = housingpayment0.40, isgrid = F, ispoint=F)
	
	# Total Income:
	income0.20 <- Household0.20$LABOUR_INCOME + Household0.20$CAPITAL_INCOME
	income0.25 <- Household0.25$LABOUR_INCOME + Household0.25$CAPITAL_INCOME
	income0.30 <- Household0.30$LABOUR_INCOME + Household0.30$CAPITAL_INCOME
	income0.40 <- Household0.40$LABOUR_INCOME + Household0.40$CAPITAL_INCOME
	
	meanincome0.20 <- get_means(nHouseholds, nQuarters, income0.20)
	meanincome0.25 <- get_means(nHouseholds, nQuarters, income0.25)
	meanincome0.30 <- get_means(nHouseholds, nQuarters, income0.30)
	meanincome0.40 <- get_means(nHouseholds, nQuarters, income0.40)
	
	ratiopayment0.20 <- housingpayment0.20 / meanincome0.20
	ratiopayment0.25 <- housingpayment0.25 / meanincome0.25
	ratiopayment0.30 <- housingpayment0.30 / meanincome0.30
	ratiopayment0.40 <- housingpayment0.40 / meanincome0.40
	
	plot_time_series_multiline_point_file(length(housingpayment0.20), ratiopayment0.20, ratiopayment0.25,  "Quarters", "Ratios", "Households's Housing Payments Ratio to their Total Income Level (mean)", "HousingPaymentRatio.png", c("beta = 0.20", "beta = 0.25", "beta = 0.30", "beta = 0.40"), v3 = ratiopayment0.30, v4 = ratiopayment0.40, isgrid = F, ispoint=F)
	}
	
# Identity Comparisons:
file = paste(data_dir, '/0.20/', "ICEACE_identity_bank.txt", sep ='')
banksData0.20 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
file = paste(data_dir, '/0.25/', "ICEACE_identity_bank.txt", sep ='')
banksData0.25 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
file = paste(data_dir, '/0.30/', "ICEACE_identity_bank.txt", sep ='')
banksData0.30 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
file = paste(data_dir, '/0.40/', "ICEACE_identity_bank.txt", sep ='')
banksData0.40 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)



iloans0.20 <- get_aggregate_values(banksData0.20$IT_NO, banksData0.20$LOANS)
imortgages0.20 <- get_aggregate_values(banksData0.20$IT_NO, banksData0.20$MORTGAGES)
idepositsPrivate0.20 <- get_aggregate_values(banksData0.20$IT_NO, banksData0.20$DEPOSITS)
iequity0.20 <- get_aggregate_values(banksData0.20$IT_NO, banksData0.20$EQUITY)
idepositsPublic0.20 <- Centralbank0.20$LIQUIDITY_GOVERNMENT
iliquidityBanks0.20 <- Centralbank0.20$LIQUIDITY_BANKS
icredit_Centralbank0.20 <- iloans0.20 + imortgages0.20
right_sideOne0.20 <- idepositsPrivate0.20 + iequity0.20 + idepositsPublic0.20
differenceOne0.20 <- icredit_Centralbank0.20 - right_sideOne0.20

moneysources <- Centralbank0.20$LOANS_BANK + Centralbank0.20$LOANS_GOVERNMENT
moneylocations <- Centralbank0.20$LIQUIDITY_BANKS + Centralbank0.20$LIQUIDITY_GOVERNMENT + Centralbank0.20$LIQUIDITY_EQUITYFUND
differenceTwo0.20 <- moneysources - moneylocations


iloans0.25 <- get_aggregate_values(banksData0.25$IT_NO, banksData0.25$LOANS)
imortgages0.25 <- get_aggregate_values(banksData0.25$IT_NO, banksData0.25$MORTGAGES)
idepositsPrivate0.25 <- get_aggregate_values(banksData0.25$IT_NO, banksData0.25$DEPOSITS)
iequity0.25 <- get_aggregate_values(banksData0.25$IT_NO, banksData0.25$EQUITY)
idepositsPublic0.25 <- Centralbank0.25$LIQUIDITY_GOVERNMENT
iliquidityBanks0.25 <- Centralbank0.25$LIQUIDITY_BANKS
icredit_Centralbank0.25 <- iloans0.25 + imortgages0.25
right_sideOne0.25 <- idepositsPrivate0.25 + iequity0.25 + idepositsPublic0.25
differenceOne0.25 <- icredit_Centralbank0.25 - right_sideOne0.25

moneysources <- Centralbank0.25$LOANS_BANK + Centralbank0.25$LOANS_GOVERNMENT
moneylocations <- Centralbank0.25$LIQUIDITY_BANKS + Centralbank0.25$LIQUIDITY_GOVERNMENT + Centralbank0.25$LIQUIDITY_EQUITYFUND
differenceTwo0.25 <- moneysources - moneylocations


iloans0.30 <- get_aggregate_values(banksData0.30$IT_NO, banksData0.30$LOANS)
imortgages0.30 <- get_aggregate_values(banksData0.30$IT_NO, banksData0.30$MORTGAGES)
idepositsPrivate0.30 <- get_aggregate_values(banksData0.30$IT_NO, banksData0.30$DEPOSITS)
iequity0.30 <- get_aggregate_values(banksData0.30$IT_NO, banksData0.30$EQUITY)
idepositsPublic0.30 <- Centralbank0.30$LIQUIDITY_GOVERNMENT
iliquidityBanks0.30 <- Centralbank0.30$LIQUIDITY_BANKS
icredit_Centralbank0.30 <- iloans0.30 + imortgages0.30
right_sideOne0.30 <- idepositsPrivate0.30 + iequity0.30 + idepositsPublic0.30
differenceOne0.30 <- icredit_Centralbank0.30 - right_sideOne0.30

moneysources <- Centralbank0.30$LOANS_BANK + Centralbank0.30$LOANS_GOVERNMENT
moneylocations <- Centralbank0.30$LIQUIDITY_BANKS + Centralbank0.30$LIQUIDITY_GOVERNMENT + Centralbank0.30$LIQUIDITY_EQUITYFUND
differenceTwo0.30 <- moneysources - moneylocations

iloans0.40 <- get_aggregate_values(banksData0.40$IT_NO, banksData0.40$LOANS)
imortgages0.40 <- get_aggregate_values(banksData0.40$IT_NO, banksData0.40$MORTGAGES)
idepositsPrivate0.40 <- get_aggregate_values(banksData0.40$IT_NO, banksData0.40$DEPOSITS)
iequity0.40 <- get_aggregate_values(banksData0.40$IT_NO, banksData0.40$EQUITY)
idepositsPublic0.40 <- Centralbank0.40$LIQUIDITY_GOVERNMENT
iliquidityBanks0.40 <- Centralbank0.40$LIQUIDITY_BANKS
icredit_Centralbank0.40 <- iloans0.40 + imortgages0.40
right_sideOne0.40 <- idepositsPrivate0.40 + iequity0.40 + idepositsPublic0.40
differenceOne0.40 <- icredit_Centralbank0.40 - right_sideOne0.40


moneysources <- Centralbank0.40$LOANS_BANK + Centralbank0.40$LOANS_GOVERNMENT
moneylocations <- Centralbank0.40$LIQUIDITY_BANKS + Centralbank0.40$LIQUIDITY_GOVERNMENT + Centralbank0.40$LIQUIDITY_EQUITYFUND
differenceTwo0.40 <- moneysources - moneylocations

minval <- min(c(right_sideOne0.20, right_sideOne0.25, right_sideOne0.30, right_sideOne0.40))
maxval <- max(c(icredit_Centralbank0.20,icredit_Centralbank0.25,icredit_Centralbank0.30, icredit_Centralbank0.40))

plot_time_series_multiline_point_file(length(differenceOne0.20), differenceOne0.20, differenceOne0.25,  "Quarters", "Amount", "Iceace Identity I", "IceaceIdentityI.png", c("beta = 0.20", "beta = 0.25", "beta = 0.30", "beta = 0.40"), v3 = differenceOne0.30, v4 = differenceOne0.40, isgrid = F, ispoint=F, maxv = maxval, minv = minval)

plot_time_series_multiline_point_file(length(differenceTwo0.20), differenceTwo0.20, differenceTwo0.25,  "Quarters", "Amount", "Iceace Identity II", "IceaceIdentityII.png", c("beta = 0.20", "beta = 0.25", "beta = 0.30", "beta = 0.40"), v3 = differenceTwo0.30, v4 = differenceTwo0.40, isgrid = F, ispoint=F, maxv = maxval, minv = minval)
	
