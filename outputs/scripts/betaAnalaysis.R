### Init Workspace  ###
rm(list = ls())
source("/Users/bulent/Documents/AWorkspace/iceace/FLAME/outputs/scripts/LibIceace.R", echo = TRUE)
data_dir = "/Users/bulent/Documents/AWorkspace/iceace/FLAME/outputs/data"
output_dir = "/Users/bulent/Documents/AWorkspace/iceace/FLAME/outputs/plots/"
setwd(output_dir)

# Unemployment Rates:

file = paste(data_dir, '/0.20/', "Government_snapshot.txt", sep ='')
Government0.20 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
file = paste(data_dir, '/0.50/', "Government_snapshot.txt", sep ='')
Government0.50 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
file = paste(data_dir, '/0.30/', "Government_snapshot.txt", sep ='')
Government0.30 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
file = paste(data_dir, '/0.40/', "Government_snapshot.txt", sep ='')
Government0.40 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)

unemployemnt0.40 <- Government0.40$UNEMPLOYMENT_RATE
unemployemnt0.30 <- Government0.30$UNEMPLOYMENT_RATE
unemployemnt0.50 <- Government0.50$UNEMPLOYMENT_RATE
unemployemnt0.20 <- Government0.20$UNEMPLOYMENT_RATE
plot_time_series_multiline_point_file(length(unemployemnt0.20), unemployemnt0.20, unemployemnt0.50, "Quarters", "Rate", "Unemployment Rates", "Unemployment.png", c("beta = 0.20", "beta = 0.50", "beta = 0.30", "beta = 0.40"), v3 = unemployemnt0.30, v4 = unemployemnt0.40, isgrid = T, ispoint = F)

# Wages:
wages0.40 <- Government0.40$AVERAGE_WAGE
wages0.30 <- Government0.30$AVERAGE_WAGE
wages0.50 <- Government0.50$AVERAGE_WAGE
wages0.20 <- Government0.20$AVERAGE_WAGE
plot_time_series_multiline_point_file(length(wages0.20), wages0.20, wages0.50, "Quarters", "Rate", "Average Wages", "Wages.png", c("beta = 0.20", "beta = 0.50", "beta = 0.30", "beta = 0.40"), v3 = wages0.30, v4 = wages0.40, isgrid = T, ispoint = F)


# Government Deficits:
balance0.20 <- Government0.20$EARNINGS - Government0.20$EXPENDITURES
balance0.50 <- Government0.50$EARNINGS - Government0.50$EXPENDITURES
balance0.30 <- Government0.30$EARNINGS - Government0.30$EXPENDITURES
balance0.40 <- Government0.40$EARNINGS - Government0.40$EXPENDITURES
plot_time_series_multiline_point_file(length(balance0.20), balance0.20, balance0.50, "Quarters", "Amount", "Government Deficit (Earnings - Expenditures)", "GovernmentDeficit.png", c("beta = 0.20", "beta = 0.50", "beta = 0.30", "beta = 0.40"), v3 = balance0.30, v4 = balance0.40, isgrid = F, ispoint = F)


# Interest Rates:

file = paste(data_dir, '/0.20/', "CentralBank_snapshot.txt", sep ='')
Centralbank0.20 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
file = paste(data_dir, '/0.50/', "CentralBank_snapshot.txt", sep ='')
Centralbank0.50 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
file = paste(data_dir, '/0.30/', "CentralBank_snapshot.txt", sep ='')
Centralbank0.30 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
file = paste(data_dir, '/0.40/', "CentralBank_snapshot.txt", sep ='')
Centralbank0.40 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)

interestrate0.20 <- Centralbank0.20$INTEREST_RATE
interestrate0.50 <- Centralbank0.50$INTEREST_RATE
interestrate0.30 <- Centralbank0.30$INTEREST_RATE
interestrate0.40 <- Centralbank0.40$INTEREST_RATE
plot_time_series_multiline_point_file(length(interestrate0.20), interestrate0.20, interestrate0.50, "Quarters", "Rate", "Central Bank Interest Rates", "InterestRate.png", c("beta = 0.20", "beta = 0.50", "beta = 0.30", "beta = 0.40"),  v3 = interestrate0.30, v4 = interestrate0.40, isgrid = F, ispoint = F)

# Inflations: 
inflation0.20 <- Centralbank0.20$INFLATION_RATE
inflation0.50 <- Centralbank0.50$INFLATION_RATE
inflation0.30 <- Centralbank0.30$INFLATION_RATE
inflation0.40 <- Centralbank0.40$INFLATION_RATE
plot_time_series_multiline_point_file(length(inflation0.20), inflation0.20, inflation0.50,  "Quarters", "Rate", "Inflation Rates", "Inflation.png", c("beta = 0.20", "beta = 0.50", "beta = 0.30", "beta = 0.40"), v3 = inflation0.30, v4 = inflation0.40, isgrid = F, ispoint = F)


# Goods Prices

file = paste(data_dir, '/0.20/', "Mall_snapshot.txt", sep ='')
Mall0.20 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
file = paste(data_dir, '/0.50/', "Mall_snapshot.txt", sep ='')
Mall0.50 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
file = paste(data_dir, '/0.30/', "Mall_snapshot.txt", sep ='')
Mall0.30<- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
file = paste(data_dir, '/0.40/', "Mall_snapshot.txt", sep ='')
Mall0.40 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)

goodsprices0.20 <- Mall0.20$AVG_GOODS_PRICE
goodsprices0.50 <- Mall0.50$AVG_GOODS_PRICE
goodsprices0.30 <- Mall0.30$AVG_GOODS_PRICE
goodsprices0.40 <- Mall0.40$AVG_GOODS_PRICE
plot_time_series_multiline_point_file(length(goodsprices0.20), goodsprices0.20, goodsprices0.50, "Weeks", "Unit Price", "Average Goods Prices (realized)", "AvgGoodsPrices.png", c("beta = 0.20", "beta = 0.50", "beta = 0.30", "beta = 0.40"), v3 = goodsprices0.30, v4 = goodsprices0.40, isgrid = F, ispoint = F)

# Housing Prices:

file = paste(data_dir, '/0.20/', "REAgency_snapshot.txt", sep ='')
REAgency0.20 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
file = paste(data_dir, '/0.50/', "REAgency_snapshot.txt", sep ='')
REAgency0.50 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
file = paste(data_dir, '/0.30/', "REAgency_snapshot.txt", sep ='')
REAgency0.30 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
file = paste(data_dir, '/0.40/', "REAgency_snapshot.txt", sep ='')
REAgency0.40 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)

# Nominal
nhousingprices0.20 <- REAgency0.20$AVG_HOUSING_PRICE
nhousingprices0.50 <- REAgency0.50$AVG_HOUSING_PRICE
nhousingprices0.30 <- REAgency0.30$AVG_HOUSING_PRICE
nhousingprices0.40 <- REAgency0.40$AVG_HOUSING_PRICE

plot_time_series_multiline_point_file(length(nhousingprices0.20), nhousingprices0.20, nhousingprices0.50,  "Months", "Average Prices", "Average Housing Unit Prices (Nominal)", "AvgHousingPricesNominal.png", c("beta = 0.20", "beta = 0.50", "beta = 0.30", "beta = 0.40"), isgrid = F, ispoint = F, v3 = nhousingprices0.30, v4 = nhousingprices0.40)

# Real -
L <- 1:length(goodsprices0.20)
L <- L %% 4
L <- L == 1
mgoodsprices0.20 <- goodsprices0.20[L]
mgoodsprices0.50 <- goodsprices0.50[L]
mgoodsprices0.30 <- goodsprices0.30[L]
mgoodsprices0.40 <- goodsprices0.40[L]

cpi0.20 <- mgoodsprices0.20 / mgoodsprices0.20[1]
cpi0.50 <- mgoodsprices0.50 / mgoodsprices0.50[1]
cpi0.30 <- mgoodsprices0.30 / mgoodsprices0.30[1]
cpi0.40 <- mgoodsprices0.40 / mgoodsprices0.40[1]

rhousingprices0.20 <- nhousingprices0.20 / cpi0.20
rhousingprices0.50 <- nhousingprices0.50 / cpi0.50
rhousingprices0.30 <- nhousingprices0.30 / cpi0.30
rhousingprices0.40 <- nhousingprices0.40 / cpi0.40


plot_time_series_multiline_point_file(length(rhousingprices0.20), rhousingprices0.20, rhousingprices0.50,  "Months", "Price Indices", "Housing Unit Price Indices", "AvgHousingPricesReal.png", c("beta = 0.20", "beta = 0.50", "beta = 0.30", "beta = 0.40"), v3 = rhousingprices0.30, v4 = rhousingprices0.40, legposn = "bottomright", isgrid = T, ispoint = F)


# Capital Income:
file = paste(data_dir, '/0.20/', "EquityFund_snapshot.txt", sep ='')
Equityfund0.20 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
file = paste(data_dir, '/0.50/', "EquityFund_snapshot.txt", sep ='')
Equityfund0.50 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
file = paste(data_dir, '/0.30/', "EquityFund_snapshot.txt", sep ='')
Equityfund0.30 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
file = paste(data_dir, '/0.40/', "EquityFund_snapshot.txt", sep ='')
Equityfund0.40 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)

dividendspaid0.20 <- Equityfund0.20$DIVIDENDS_PAID
dividendspaid0.50 <- Equityfund0.50$DIVIDENDS_PAID
dividendspaid0.30 <- Equityfund0.30$DIVIDENDS_PAID
dividendspaid0.40 <- Equityfund0.40$DIVIDENDS_PAID

plot_time_series_multiline_point_file(length(dividendspaid0.20), dividendspaid0.20, dividendspaid0.50,  "Quarters", "Amount", "Dividends Paid", "DividendsPaid.png", c("beta = 0.20", "beta = 0.50", "beta = 0.30", "beta = 0.40"), v3 = dividendspaid0.30, v4 = dividendspaid0.40, isgrid = F, ispoint=F)

# Loans:
file = paste(data_dir, '/0.20/', "Bank_BalanceSheet.txt", sep ='')
BankBalance0.20 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
file = paste(data_dir, '/0.50/', "Bank_BalanceSheet.txt", sep ='')
BankBalance0.50 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
file = paste(data_dir, '/0.30/', "Bank_BalanceSheet.txt", sep ='')
BankBalance0.30 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
file = paste(data_dir, '/0.40/', "Bank_BalanceSheet.txt", sep ='')
BankBalance0.40 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)

loans0.20 <- get_aggregate_values(BankBalance0.20$IT_NO, BankBalance0.20$LOANS)
loans0.50 <- get_aggregate_values(BankBalance0.50$IT_NO, BankBalance0.50$LOANS)
loans0.30 <- get_aggregate_values(BankBalance0.30$IT_NO, BankBalance0.30$LOANS)
loans0.40 <- get_aggregate_values(BankBalance0.40$IT_NO, BankBalance0.40$LOANS)

plot_time_series_multiline_point_file(length(loans0.20), loans0.20, loans0.50, "Quarters", "Total Amount", "Loans to Firms", "Loans.png", c("beta = 0.20", "beta = 0.50", "beta = 0.30", "beta = 0.40"), v3 = loans0.30, v4 = loans0.40, isgrid = F, ispoint=F)


# Mortgages:
mortgages0.20 <- get_aggregate_values(BankBalance0.20$IT_NO, BankBalance0.20$MORTGAGES)
mortgages0.50 <- get_aggregate_values(BankBalance0.50$IT_NO, BankBalance0.50$MORTGAGES)
mortgages0.30 <- get_aggregate_values(BankBalance0.30$IT_NO, BankBalance0.30$MORTGAGES)
mortgages0.40 <- get_aggregate_values(BankBalance0.40$IT_NO, BankBalance0.40$MORTGAGES)

plot_time_series_multiline_point_file(length(mortgages0.20), mortgages0.20, mortgages0.50,  "Quarters", "Total Amount", "Mortgages to Households", "Mortgages.png", c("beta = 0.20", "beta = 0.50", "beta = 0.30", "beta = 0.40"), v3 = mortgages0.30, v4 = mortgages0.40, isgrid = F, ispoint=F)

# Private Sector Debt:
privatedebt0.20 <- mortgages0.20 + loans0.20
privatedebt0.50 <- mortgages0.50 + loans0.50
privatedebt0.30 <- mortgages0.30 + loans0.30
privatedebt0.40 <- mortgages0.40 + loans0.40

plot_time_series_multiline_point_file(length(privatedebt0.20), privatedebt0.20, privatedebt0.50,  "Quarters", "Total Amount", "Private Sector Debt", "PrivateSectorDebt.png", c("beta = 0.20", "beta = 0.50", "beta = 0.30", "beta = 0.40"), v3 = privatedebt0.30, v4 = privatedebt0.40, isgrid = F, ispoint=F)

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


#0.50:

file = paste(data_dir, '/0.50/', "Firm_Monthly.txt", sep ='')
FirmMonthly0.50 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
file = paste(data_dir, '/0.50/', "Constructor_Firm_Monthly.txt", sep ='')
CFirmMonthly0.50 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)

FirmMonthly0.50$Nominal <- FirmMonthly0.50$PRODUCTION_CURRENT * FirmMonthly0.50$UNIT_GOODS_PRICE
FirmMonthly0.50$Real <- FirmMonthly0.50$PRODUCTION_CURRENT * FirmMonthly0.50$UNIT_GOODS_PRICE[1]

CFirmMonthly0.50$Nominal <- CFirmMonthly0.50$PRODUCTION_CURRENT * CFirmMonthly0.50$UNIT_HOUSE_PRICE
CFirmMonthly0.50$Real <- CFirmMonthly0.50$PRODUCTION_CURRENT * CFirmMonthly0.50$UNIT_HOUSE_PRICE[1]

gdpnominal0.50 <- get_aggregate_values_v2(FirmMonthly0.50$IT_NO, FirmMonthly0.50$Nominal, nMonths) + get_aggregate_values_v2(CFirmMonthly0.50$IT_NO, CFirmMonthly0.50$Nominal, nMonths)
gdpreal0.50 <- get_aggregate_values_v2(FirmMonthly0.50$IT_NO, FirmMonthly0.50$Real, nMonths) + get_aggregate_values_v2(CFirmMonthly0.50$IT_NO, CFirmMonthly0.50$Real, nMonths)

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

plot_time_series_multiline_point_file(length(gdpnominal0.20), gdpnominal0.20, gdpnominal0.50, "Months", "Total Goods and Housing Units", "GDP - Nominal", "GDP_Nominal.png", c("beta = 0.20", "beta = 0.50", "beta = 0.30", "beta = 0.40"), v3 = gdpnominal0.30, v4 = gdpnominal0.40, isgrid = F, ispoint=F)

plot_time_series_multiline_point_file(length(gdpreal0.20), gdpreal0.20, gdpreal0.50, "Months", "Total Goods and Housing Units", "GDP - Real", "GDP_Real.png", c("beta = 0.20", "beta = 0.50", "beta = 0.30", "beta = 0.40"), v3 = gdpreal0.30, v4 = gdpreal0.40, isgrid = F, ispoint=F)


data_household = 1

if (data_household){
	file = paste(data_dir, '/0.20/', "Household_Quarterly.txt", sep ='')
	Household0.20 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
	file = paste(data_dir, '/0.50/', "Household_Quarterly.txt", sep ='')
	Household0.50 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
	file = paste(data_dir, '/0.30/', "Household_Quarterly.txt", sep ='')
	Household0.30 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
	file = paste(data_dir, '/0.40/', "Household_Quarterly.txt", sep ='')
	Household0.40 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
	
	nQuarters <- length(Centralbank0.20$IT_NO)
	nHouseholds <- length(Household0.20$IT_NO)/nQuarters

    # Housing Payment:
	housingpayment0.20 <- get_means(nHouseholds, nQuarters, Household0.20$HOUSING_PAYMENT)
	housingpayment0.50 <- get_means(nHouseholds, nQuarters, Household0.50$HOUSING_PAYMENT)
	housingpayment0.30 <- get_means(nHouseholds, nQuarters, Household0.30$HOUSING_PAYMENT)
	housingpayment0.40 <- get_means(nHouseholds, nQuarters, Household0.40$HOUSING_PAYMENT)
	
	plot_time_series_multiline_point_file(length(housingpayment0.20), housingpayment0.20, housingpayment0.50,  "Quarters", "Mean Housing Payments", "Households's Mean Housing Payments", "HousingPayment.png", c("beta = 0.20", "beta = 0.50", "beta = 0.30", "beta = 0.40"), v3 = housingpayment0.30, v4 = housingpayment0.40, isgrid = F, ispoint=F)
	
	# Total Income:
	income0.20 <- Household0.20$LABOUR_INCOME + Household0.20$CAPITAL_INCOME
	income0.50 <- Household0.50$LABOUR_INCOME + Household0.50$CAPITAL_INCOME
	income0.30 <- Household0.30$LABOUR_INCOME + Household0.30$CAPITAL_INCOME
	income0.40 <- Household0.40$LABOUR_INCOME + Household0.40$CAPITAL_INCOME
	
	meanincome0.20 <- get_means(nHouseholds, nQuarters, income0.20)
	meanincome0.50 <- get_means(nHouseholds, nQuarters, income0.50)
	meanincome0.30 <- get_means(nHouseholds, nQuarters, income0.30)
	meanincome0.40 <- get_means(nHouseholds, nQuarters, income0.40)
	
	ratiopayment0.20 <- housingpayment0.20 / meanincome0.20
	ratiopayment0.50 <- housingpayment0.50 / meanincome0.50
	ratiopayment0.30 <- housingpayment0.30 / meanincome0.30
	ratiopayment0.40 <- housingpayment0.40 / meanincome0.40
	
	plot_time_series_multiline_point_file(length(housingpayment0.20), ratiopayment0.20, ratiopayment0.50,  "Quarters", "Ratios", "Households's Housing Payments Ratio to their Total Income Level (mean)", "HousingPaymentRatio.png", c("beta = 0.20", "beta = 0.50", "beta = 0.30", "beta = 0.40"), v3 = ratiopayment0.30, v4 = ratiopayment0.40, isgrid = F, ispoint=F)
	}
	
# Identity Compariosons:
file = paste(data_dir, '/0.20/', "ICEACE_identity_bank.txt", sep ='')
banksData0.20 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
file = paste(data_dir, '/0.50/', "ICEACE_identity_bank.txt", sep ='')
banksData0.50 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
file = paste(data_dir, '/0.30/', "ICEACE_identity_bank.txt", sep ='')
banksData0.30 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
file = paste(data_dir, '/0.40/', "ICEACE_identity_bank.txt", sep ='')
banksData0.40 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)

file = paste(data_dir, '/0.20/', "ICEACE_identity_cb.txt", sep ='')
money0.20 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
file = paste(data_dir, '/0.50/', "ICEACE_identity_cb.txt", sep ='')
money0.50 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
file = paste(data_dir, '/0.30/', "ICEACE_identity_cb.txt", sep ='')
money0.30 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
file = paste(data_dir, '/0.40/', "ICEACE_identity_cb.txt", sep ='')
money0.40 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)

iloans0.20 <- get_aggregate_values(banksData0.20$IT_NO, banksData0.20$LOANS)
imortgages0.20 <- get_aggregate_values(banksData0.20$IT_NO, banksData0.20$MORTGAGES)
idepositsPrivate0.20 <- get_aggregate_values(banksData0.20$IT_NO, banksData0.20$DEPOSITS)
iequity0.20 <- get_aggregate_values(banksData0.20$IT_NO, banksData0.20$EQUITY)
idepositsPublic0.20 <- money0.20$LIQUIDITY_GOVERNMENT
iliquidityBanks0.20 <- Centralbank0.20$LIQUIDITY_BANKS
icredit_money0.20 <- iloans0.20 + imortgages0.20
right_sideOne0.20 <- idepositsPrivate0.20 + iequity0.20 + idepositsPublic0.20
differenceOne0.20 <- icredit_money0.20 - right_sideOne0.20
differenceTwo0.20 <- iloans0.20 - iliquidityBanks0.20

iloans0.20 <- get_aggregate_values(banksData0.20$IT_NO, banksData0.20$LOANS)
imortgages0.20 <- get_aggregate_values(banksData0.20$IT_NO, banksData0.20$MORTGAGES)
idepositsPrivate0.20 <- get_aggregate_values(banksData0.20$IT_NO, banksData0.20$DEPOSITS)
iequity0.20 <- get_aggregate_values(banksData0.20$IT_NO, banksData0.20$EQUITY)
idepositsPublic0.20 <- money0.20$LIQUIDITY_GOVERNMENT
iliquidityBanks0.20 <- Centralbank0.20$LIQUIDITY_BANKS
icredit_money0.20 <- iloans0.20 + imortgages0.20
right_sideOne0.20 <- idepositsPrivate0.20 + iequity0.20 + idepositsPublic0.20
differenceOne0.20 <- icredit_money0.20 - right_sideOne0.20
differenceTwo0.20 <- iloans0.20 - iliquidityBanks0.20

iloans0.50 <- get_aggregate_values(banksData0.50$IT_NO, banksData0.50$LOANS)
imortgages0.50 <- get_aggregate_values(banksData0.50$IT_NO, banksData0.50$MORTGAGES)
idepositsPrivate0.50 <- get_aggregate_values(banksData0.50$IT_NO, banksData0.50$DEPOSITS)
iequity0.50 <- get_aggregate_values(banksData0.50$IT_NO, banksData0.50$EQUITY)
idepositsPublic0.50 <- money0.50$LIQUIDITY_GOVERNMENT
iliquidityBanks0.50 <- Centralbank0.50$LIQUIDITY_BANKS
icredit_money0.50 <- iloans0.50 + imortgages0.50
right_sideOne0.50 <- idepositsPrivate0.50 + iequity0.50 + idepositsPublic0.50
differenceOne0.50 <- icredit_money0.50 - right_sideOne0.50
differenceTwo0.50 <- iloans0.50 - iliquidityBanks0.50

iloans0.30 <- get_aggregate_values(banksData0.30$IT_NO, banksData0.30$LOANS)
imortgages0.30 <- get_aggregate_values(banksData0.30$IT_NO, banksData0.30$MORTGAGES)
idepositsPrivate0.30 <- get_aggregate_values(banksData0.30$IT_NO, banksData0.30$DEPOSITS)
iequity0.30 <- get_aggregate_values(banksData0.30$IT_NO, banksData0.30$EQUITY)
idepositsPublic0.30 <- money0.30$LIQUIDITY_GOVERNMENT
iliquidityBanks0.30 <- Centralbank0.30$LIQUIDITY_BANKS
icredit_money0.30 <- iloans0.30 + imortgages0.30
right_sideOne0.30 <- idepositsPrivate0.30 + iequity0.30 + idepositsPublic0.30
differenceOne0.30 <- icredit_money0.30 - right_sideOne0.30
differenceTwo0.30 <- iloans0.30 - iliquidityBanks0.30

iloans0.40 <- get_aggregate_values(banksData0.40$IT_NO, banksData0.40$LOANS)
imortgages0.40 <- get_aggregate_values(banksData0.40$IT_NO, banksData0.40$MORTGAGES)
idepositsPrivate0.40 <- get_aggregate_values(banksData0.40$IT_NO, banksData0.40$DEPOSITS)
iequity0.40 <- get_aggregate_values(banksData0.40$IT_NO, banksData0.40$EQUITY)
idepositsPublic0.40 <- money0.40$LIQUIDITY_GOVERNMENT
iliquidityBanks0.40 <- Centralbank0.40$LIQUIDITY_BANKS
icredit_money0.40 <- iloans0.40 + imortgages0.40
right_sideOne0.40 <- idepositsPrivate0.40 + iequity0.40 + idepositsPublic0.40
differenceOne0.40 <- icredit_money0.40 - right_sideOne0.40
differenceTwo0.40 <- iloans0.40 - iliquidityBanks0.40

minval <- min(c(right_sideOne0.20, right_sideOne0.50, right_sideOne0.30, right_sideOne0.40))
maxval <- max(c(icredit_money0.20,icredit_money0.50,icredit_money0.30, icredit_money0.40))

plot_time_series_multiline_point_file(length(differenceOne0.20), differenceOne0.20, differenceOne0.50,  "Quarters", "Amount", "Iceace Identity I", "IceaceIdentityI.png", c("beta = 0.20", "beta = 0.50", "beta = 0.30", "beta = 0.40"), v3 = differenceOne0.30, v4 = differenceOne0.40, isgrid = F, ispoint=F, maxv = maxval, minv = minval)

plot_time_series_multiline_point_file(length(differenceTwo0.20), differenceTwo0.20, differenceTwo0.50,  "Quarters", "Amount", "Iceace Identity II", "IceaceIdentityII.png", c("beta = 0.20", "beta = 0.50", "beta = 0.30", "beta = 0.40"), v3 = differenceTwo0.30, v4 = differenceTwo0.40, isgrid = F, ispoint=F, maxv = maxval, minv = minval)
	
