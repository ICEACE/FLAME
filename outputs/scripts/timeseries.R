### Init workspace  ###

rm(list = ls())
source("/Users/bulent/Documents/AWorkspace/iceace/FLAME/outputs/scripts/LibAnals.R", echo = TRUE)

# Importing Datasets #
data_dir = "/Users/bulent/Documents/AWorkspace/iceace/FLAME/outputs/data"
output_dir = "/Users/bulent/Documents/AWorkspace/iceace/FLAME/outputs/plots/"
setwd(output_dir)

### Single Run Anals ###
file = paste(data_dir, '/', "Government_snapshot.txt", sep ='')
Government <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)

file = paste(data_dir, '/', "CentralBank_snapshot.txt", sep ='')
Centralbank <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)

file = paste(data_dir, '/', "EquityFund_snapshot.txt", sep ='')
Equityfund <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)

file = paste(data_dir, '/', "Mall_snapshot.txt", sep ='')
Mall <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)

file = paste(data_dir, '/', "REAgency_snapshot.txt", sep ='')
REAgency <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)

file = paste(data_dir, '/', "Bank_BalanceSheet.txt", sep ='')
BankBalance <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)

file = paste(data_dir, '/', "Bank_IncomeStatement.txt", sep ='')
BankIncome <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)

file = paste(data_dir, '/', "Firm_Monthly.txt", sep ='')
FirmMonthly <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
file = paste(data_dir, '/', "Constructor_Firm_Monthly.txt", sep ='')
CFirmMonthly <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)

file = paste(data_dir, '/', "Firm_Quarterly_BalanceSheet.txt", sep ='')
FirmBalance <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
file = paste(data_dir, '/', "Constructor_Firm_Quarterly_BalanceSheet.txt", sep ='')
CFirmBalance <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)

file = paste(data_dir, '/', "Firm_Quarterly_IncomeStatement.txt", sep ='')
FirmIncome <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
file = paste(data_dir, '/', "Constructor_Firm_Quarterly_IncomeStatement.txt", sep ='')
CFirmIncome <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)

file = paste(data_dir, '/', "Firm_Quarterly_Dividends.txt", sep ='')
FirmDividends <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
file = paste(data_dir, '/', "Constructor_Firm_Quarterly_Dividends.txt", sep ='')
CFirmDividends <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)

nWeeks <- length(Mall$IT_NO)
nMonths <- length(REAgency$IT_NO)
nQuarters <- length(Equityfund$IT_NO)
nFirms = length(FirmIncome$ID) / nQuarters
nCFirms = length(CFirmIncome$ID) / nQuarters
nBanks = length(BankIncome$ID) / nQuarters


#MALL:
plot_time_series_point_file(nWeeks, Mall$AVG_GOODS_PRICE, "Weeks", "Average Unit Goods Price", "Consumption Goods Market", "MallAvgGoodsPrice.png")
plot_time_series_point_file(nWeeks, Mall$TRANSACTION_QUANTITY, "Weeks", "Number of Transactions", "Consumption Goods Market", "MallTransactionVolumeGoods.png")

#Real Estate Agency
plot_time_series_point_file(nMonths, REAgency$AVG_HOUSING_PRICE, "Months", "Average Unit Housing Price", "Real Estate Market", "REAgencyAvgHousingPrice.png")
plot_time_series_point_file(nMonths, REAgency$TRANSACTION_QUANTITY, "Months", "Number of Housing Transactions", "Real Estate Market", "REAgencyTransactionVolumeHouses.png")

#Central Bank
plot_time_series_point_file(nQuarters, Centralbank$INTEREST_RATE, "Quarters", "Interest Rate", "Central Bank", "CentralBankInterestRate.png")
plot_time_series_point_file(nQuarters, Centralbank$INFLATION, "Quarters", "Inflation", "Central Bank", "CentralBankInflation.png")
plot_time_series_point_file(nQuarters, Centralbank$REVENUES, "Quarters", "Interests Accrued", "Central Bank", "CentralBankRevenues.png")
plot_time_series_point_file(nQuarters, Centralbank$FIAT_MONEY, "Quarters", "FIAT Money", "Central Bank", "CentralBankFiatMoney.png")
plot_time_series_point_file(nQuarters, Centralbank$TOTAL_ASSETS, "Quarters", "Total Assets", "Central Bank", "CentralBankTotalAssets.png")
plot_time_series_point_file(nQuarters, Centralbank$LIQUIDITY, "Quarters", "Liquidity", "Central Bank", "CentralBankLiquidity.png")
plot_time_series_point_file(nQuarters, Centralbank$LOANS_BANKS, "Quarters", "Bank Loans", "Central Bank", "CentralBankLoansBanks.png")
plot_time_series_point_file(nQuarters, Centralbank$LOANS_GOVERNMENT, "Quarters", "Governement Loan", "Central Bank", "CentralBankLoansGovernment.png")
plot_time_series_point_file(nQuarters, Centralbank$EQUITY, "Quarters", "Equity", "Central Bank", "CentralBankEquity.png")
plot_time_series_point_file(nQuarters, Centralbank$LIQUIDITY_BANKS, "Quarters", "Bank Liquidity", "Central Bank", "CentralBankLiquidityBanks.png")
plot_time_series_point_file(nQuarters, Centralbank$LIQUIDITY_GOVERNMENT, "Quarters", "Government Liquidity", "Central Bank", "CentralBankLiquidityGovernment.png")
plot_time_series_point_file(nQuarters, Centralbank$LIQUIDITY_EQUITYFUND, "Quarters", "Equity Fund Liquidity", "Central Bank", "CentralBankLiquidityEquityFund.png")



#Government
plot_time_series_point_file(nQuarters, Government$UNEMPLOYMENT_RATE, "Quarters", "Unemployment Rate", "", "GovernmentUnemploymentRate.png")
plot_time_series_point_file(nQuarters, Government$LABOUR_TAX_RATE, "Quarters", "Tax Rate (labour/Capital)", "Government", "GovernmentTaxRate.png")
plot_time_series_point_file(nQuarters, Government$GOV_GENERAL_BENEFIT_RATE, "Quarters", "General Benefits Rate", "Government", "GovernmentBenefitsRate.png")
plot_time_series_point_file(nQuarters, Government$UNEMPLOYMENT_BENEFITS, "Quarters", "Unemployment Benefits", "", "GovernmentBenefitsUnemployment.png")
plot_time_series_point_file(nQuarters, Government$GENERAL_BENEFITS, "Quarters", "General Benefits", "Government", "GovernmentBenefitsGeneral.png")
plot_time_series_point_file(nQuarters, Government$AVERAGE_WAGE, "Quarters", "Average Wage", "", "GovernmentAverageWage.png")
plot_time_series_point_file(nQuarters, Government$DEBT, "Quarters", "Amount", "Government Debt to Central Bank", "GovernmentDebt.png")
plot_time_series_point_file(nQuarters, Government$CENTRALBANK_INCOME, "Quarters", "Amount", "Government Central Bank Incomes", "GovernmentCentralbankIncome.png")
plot_time_series_point_file(nQuarters, Government$LIQUIDITY, "Quarters", "Amount", "Government Liquidity", "GovernmentLiquidity.png")

#Equity Fund
plot_time_series_point_file(nQuarters, Equityfund$DIVIDENDS_RECIEVED, "Quarters", "Amount", "Equity Fund - Dividends Received", "FundDividendsReceived.png")
plot_time_series_point_file(nQuarters, Equityfund$DIVIDENDS_RETAINED, "Quarters", "Amount", "Equity Fund - Dividends Retained", "FundDividendsRetained.png")
plot_time_series_point_file(nQuarters, Equityfund$LIQUIDITY, "Quarters", "Amount", "Equity Fund - Liquidity", "FundLiquidity.png")
plot_time_series_point_file(nQuarters, Equityfund$DIVIDENDS_PAID, "Quarters", "Amount", "Equity Fund - Dividends Paid", "FundDividendsPaid.png")
beta = "0.6"
plot_time_series_multiline_point_file(nQuarters, Equityfund$SHARE_FIRMS, Equityfund$SHARE_CONSTRUCTION_FIRMS, Equityfund$SHARE_BANKS, "Quarters", "Amount", "Equity Fund - Dividends Received Components", "FundDividendsReceivedParts.png", c("Firms", "CFirms", "Banks"))

#Banks
bankA = 21
bankB = 22

plot_time_series_banks(nQuarters, BankBalance$ID, bankA, bankB, BankBalance$LOANS, "Quarters", "Loans to Firms", "Banks", "BanksLoans.png")
plot_time_series_banks(nQuarters, BankBalance$ID, bankA, bankB, BankBalance$MORTGAGES, "Quarters", "Mortgages to Households", "Banks", "BanksMortgages.png")
plot_time_series_banks(nQuarters, BankBalance$ID, bankA, bankB, BankBalance$DEPOSITS, "Quarters", "Deposits from Firms and Households", "Banks", "BanksDeposits.png")
plot_time_series_banks(nQuarters, BankBalance$ID, bankA, bankB, BankBalance$CENTRALBANK_DEBT, "Quarters", "Central Bank Debt", "Banks", "BanksDebt.png")
plot_time_series_banks(nQuarters, BankBalance$ID, bankA, bankB, BankBalance$EQUITY, "Quarters", "Equity", "Banks", "BanksEquity.png")
plot_time_series_banks(nQuarters, BankIncome$ID, bankA, bankB, BankIncome$INTERESTS_ACCRUED, "Quarters", "Interests Collected on Mortgages and Loans", "Banks", "BanksInterestsCollected.png")
plot_time_series_banks(nQuarters, BankIncome$ID, bankA, bankB, BankIncome$TOTAL_WRITEOFFS, "Quarters", "Total Loan and Mortgage Writeoffs", "Banks", "BanksWriteoffs.png")
plot_time_series_banks(nQuarters, BankIncome$ID, bankA, bankB, BankIncome$INTERESTS_PAID, "Quarters", "Interests Paid to Central Bank", "Banks", "BanksInterestsPaid.png")
plot_time_series_banks(nQuarters, BankIncome$ID, bankA, bankB, BankIncome$NET_EARNINGS, "Quarters", "Net Earnings", "Banks", "BanksNetEarnings.png")
plot_time_series_banks(nQuarters, BankIncome$ID, bankA, bankB, BankIncome$TOTAL_DIVIDENDS, "Quarters", "Dividends Sent to Fund", "Banks", "BanksTotalDividends.png")
plot_time_series_banks(nQuarters, BankBalance$ID, bankA, bankB, BankBalance$LIQUIDITY, "Quarters", "Amount", "Banks - Liquidity", "BanksLiquidity.png")



#Firms
plot_time_series_mean_file(nFirms, nQuarters, FirmBalance$UNIT_GOODS_PRICE, "Quarters", "Price (mean)", "Firms", "FirmsUnitGoodPrices.png")
plot_time_series_mean_file(nCFirms, nQuarters, CFirmBalance$UNIT_HOUSE_PRICE, "Quarters", "Price (mean)", "Constructor Firms", "CFirmsUnitHousePrices.png")

plot_time_series_mean_file(nFirms, nQuarters, FirmIncome$REVENUES, "Quarters", "Sale Revenues (mean)", "Firms", "FirmsRevenues.png")
plot_time_series_mean_file(nCFirms, nQuarters, CFirmIncome$REVENUES, "Quarters", "Sale Revenues (mean)", "Constructor Firms", "CFirmsRevenues.png")

plot_time_series_mean_file(nFirms, nQuarters, FirmIncome$LABOUR_COSTS, "Quarters", "Labour Costs (mean)", "Firms", "FirmsLabourCosts.png")
plot_time_series_mean_file(nCFirms, nQuarters, CFirmIncome$LABOUR_COSTS, "Quarters", "Labour Costs (mean)", "Constructor Firms", "CFirmsLabourCosts.png")

plot_time_series_mean_file(nFirms, nQuarters, FirmIncome$TOTAL_INTEREST_PAYMENTS, "Quarters", "Loan Interest Payments (mean)", "Firms", "FirmsInterestPayments.png")
plot_time_series_mean_file(nCFirms, nQuarters, CFirmIncome$TOTAL_INTEREST_PAYMENTS, "Quarters", "Loan Interest Payments (mean)", "Constructor Firms", "CFirmsInterestPayments.png")

plot_time_series_mean_file(nFirms, nQuarters, FirmIncome$NET_EARNINGS, "Quarters", "Net Earnings (mean)", "Firms", "FirmsNetEarnings.png")
plot_time_series_mean_file(nCFirms, nQuarters, CFirmIncome$NET_EARNINGS, "Quarters", "Net Earnings (mean)", "Constructor Firms", "CFirmsNetEarnings.png")

plot_time_series_mean_file(nFirms, nQuarters, FirmIncome$EBIT, "Quarters", "EBIT (mean)", "Firms", "FirmsEBIT.png")
plot_time_series_mean_file(nCFirms, nQuarters, CFirmIncome$EBIT, "Quarters", "EBIT (mean)", "Constructor Firms", "CFirmsEBIT.png")

plot_time_series_mean_file(nFirms, nQuarters, FirmBalance$TOTAL_ASSETS, "Quarters", "Total Assets (mean)", "Firms", "FirmsTotalAssets.png")
plot_time_series_mean_file(nCFirms, nQuarters, CFirmBalance$TOTAL_ASSETS, "Quarters", "Total Assets (mean)", "Constructor Firms", "CFirmsTotalAssets.png")

plot_time_series_mean_file(nFirms, nQuarters, FirmBalance$LIQUIDITY, "Quarters", "Liquidity (mean)", "Firms", "FirmsLiquidity.png")
plot_time_series_mean_file(nCFirms, nQuarters, CFirmBalance$LIQUIDITY, "Quarters", "Liquidity (mean)", "Constructor Firms", "CFirmsLiquidity.png")

plot_time_series_mean_file(nFirms, nQuarters, FirmBalance$DEBT, "Quarters", "Debt (mean)", "Firms", "FirmsDebt.png")
plot_time_series_mean_file(nCFirms, nQuarters, CFirmBalance$DEBT, "Quarters", "Debt (mean)", "Constructor Firms", "CFirmsDebt.png")

plot_time_series_mean_file(nFirms, nQuarters, FirmBalance$EQUITY, "Quarters", "Equity (mean)", "Firms", "FirmsEquity.png")
plot_time_series_mean_file(nCFirms, nQuarters, CFirmBalance$EQUITY, "Quarters", "Equity (mean)", "Constructor Firms", "CFirmsEquity.png")

plot_time_series_mean_file(nFirms, nQuarters, FirmBalance$CAPITAL_GOODS, "Quarters", "Capital Goods (mean)", "Firms", "FirmsCapitalGoods.png")
plot_time_series_mean_file(nCFirms, nQuarters, CFirmBalance$CAPITAL_GOODS, "Quarters", "Capital Goods (mean)", "Constructor Firms", "CFirmsCapitalGoods.png")

plot_time_series_mean_file(nFirms, nQuarters, FirmBalance$PHYSICAL_CAPITAL, "Quarters", "Physical Capital (mean)", "Firms", "FirmsPhysicalCapital.png")
plot_time_series_mean_file(nCFirms, nQuarters, CFirmBalance$PHYSICAL_CAPITAL_CONSTRUCTION, "Quarters", "Construction Physical Capital (mean)", "Constructor Firms", "CFirmsPhysicalCapital.png")


plot_time_series_mean_file_v2(nQuarters, FirmDividends$IT_NO, FirmDividends$DIVIDENDS_PAID, "Quarters", "Dividends Paid (mean)", "Firms", "FirmsDividendsPaid.png")
plot_time_series_mean_file_v2(nQuarters, CFirmDividends$IT_NO, CFirmDividends$DIVIDENDS_PAID, "Quarters", "Dividends Paid (mean)", "Constructor Firms", "CFirmsDividendsPaid.png")

plot_time_series_mean_file_v2(nMonths, FirmMonthly$IT_NO, FirmMonthly$NO_EMPLOYEES, "Months", "No Employees (mean)", "Firms", "FirmsEmployeeSize.png")
plot_time_series_mean_file_v2(nMonths, CFirmMonthly$IT_NO, CFirmMonthly$NO_EMPLOYEES, "Months", "No Employees (mean)", "Constructor Firms", "CFirmsEmployeeSize.png")

plot_time_series_mean_file_v2(nMonths, FirmMonthly$IT_NO, FirmMonthly$INVENTORY, "Months", "Inventory (mean)", "Firms", "FirmsInventory.png")
plot_time_series_mean_file_v2(nMonths, CFirmMonthly$IT_NO, CFirmMonthly$INVENTORY, "Months", "Inventory (mean)", "Constructor Firms", "CFirmsInventory.png")

plot_time_series_mean_file_v2(nMonths, FirmMonthly$IT_NO, FirmMonthly$PRODUCTION_PLAN, "Months", "Production Plan (mean)", "Firms", "FirmsProductionPlan.png")
plot_time_series_mean_file_v2(nMonths, CFirmMonthly$IT_NO, CFirmMonthly$PRODUCTION_PLAN, "Months", "Production Plan (mean)", "Constructor Firms", "CFirmsProductionPlan.png")

plot_time_series_mean_file_v2(nMonths, FirmMonthly$IT_NO, FirmMonthly$PRODUCTION_CURRENT, "Months", "Production Current (mean)", "Firms", "FirmsProductionCurrent.png")
plot_time_series_mean_file_v2(nMonths, CFirmMonthly$IT_NO, CFirmMonthly$PRODUCTION_CURRENT, "Months", "Production Current (mean)", "Constructor Firms", "CFirmsProductionCurrent.png")

plot_time_series_mean_file_v2(nMonths, FirmMonthly$IT_NO, FirmMonthly$SALES, "Months", "Sales (mean)", "Firms", "FirmsSales.png")
plot_time_series_mean_file_v2(nMonths, CFirmMonthly$IT_NO, CFirmMonthly$SALES, "Months", "Sales (mean)", "Constructor Firms", "CFirmsSales.png")





### Validation - Begin ####

# Compute GDP #
cfirmvector <- CFirmMonthly$PRODUCTION_CURRENT * CFirmMonthly$UNIT_HOUSE_PRICE
firmvector <- FirmMonthly$PRODUCTION_CURRENT * FirmMonthly$UNIT_GOODS_PRICE
plot_gdp_to_file_v1(nMonths, FirmMonthly$IT_NO,firmvector, CFirmMonthly$IT_NO, cfirmvector, gtype = "Nominal", beta = "0.30")

cfirmvector_real <- CFirmMonthly$PRODUCTION_CURRENT * CFirmMonthly$UNIT_HOUSE_PRICE[1]
firmvector_real <- FirmMonthly$PRODUCTION_CURRENT * FirmMonthly$UNIT_GOODS_PRICE[1]
plot_gdp_to_file_v1(nMonths, FirmMonthly$IT_NO,firmvector_real, CFirmMonthly$IT_NO, cfirmvector_real, gtype = "Real", beta = "0.30")

plot_gdp_to_file_v2(nMonths, FirmMonthly$IT_NO,firmvector, CFirmMonthly$IT_NO, cfirmvector, firmvector_real, cfirmvector_real, beta = "0.30")


# Compute Bankruptcy #
file = paste(data_dir, '/', "BankruptcyInspection.txt", sep ='')
Bankruptcy <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
L <- Bankruptcy$Writeoff_Type == "Insolvency"
Insolvencies <-Bankruptcy[L,]
L <- Bankruptcy$Writeoff_Type == "Illiquidity"
Illiquidities <-Bankruptcy[L,]
L <- Bankruptcy$Writeoff_Type == "Mortgage"
Mortgages <-Bankruptcy[L,]

niter <- 3600
nQuarters <- niter %/% 60
freqinsolv <- rep(0, nQuarters)
freqilliquid <- rep(0, nQuarters)
freqmort <- rep(0, nQuarters)

if (length(Insolvencies[["IT"]]) > 0) {
	Insolvencies <- get_single_occurances(Insolvencies)
	freqinsolv <- get_occurances_distro(niter, Insolvencies[["IT"]])
}

if (length(Mortgages[["IT"]]) > 0) {
	Mortgages <- get_single_occurances(Mortgages)
	freqmort <- get_occurances_distro(niter, Mortgages[["IT"]])
}

if (length(Illiquidities[["IT"]]) > 0) {
	Illiquidities <- get_single_occurances(Illiquidities)
	freqilliquid <- get_occurances_distro(niter, Illiquidities[["IT"]])
}

plot_time_series_multiline_point_file(nQuarters, freqmort, freqinsolv, freqilliquid, "Quarters", "Frequency", "Defaults", "aWriteoffTypesAndFrequencies.png", c("Mortgages", "Insolvencies", "Illiquidities"))

plot_time_series_point_file(nQuarters, freqmort, "Quarters", "Frequency", "Mortgage Writeoffs", "aWriteoffMortgages.png")

plot_time_series_point_file(nQuarters, freqilliquid, "Quarters", "Frequency", "Illiquidity Writeoffs", "aWriteoffIlliquidity.png")

plot_time_series_point_file(nQuarters, freqinsolv, "Quarters", "Frequency", "Insolvency Writeoffs", "aWriteoffInsolvency.png")


### Validation - End ###


### Households ###

HouseholdQuarterly <- read.csv('../data/Household_Quarterly.txt', sep = " ", header = T, stringsAsFactors = F)
HouseholdMonthlyFirst <- read.csv('../data/Household_Monthly_FirstDay.txt', sep = " ", header = T, stringsAsFactors = F)
HouseholdMonthlyLast <- read.csv('../data/Household_Monthly_LastDay.txt', sep = " ", header = T, stringsAsFactors = F)
HouseholdWeekly <- read.csv('../data/Household_Weekly.txt', sep = " ", header = T, stringsAsFactors = F)
nHouseholds = length(HouseholdQuarterly$"ID") / nQuarters


#Household - Quarterly
boxplot_time_series_distro_file(nHouseholds, nQuarters, HouseholdQuarterly$TOTAL_ASSETS, "Quarters", "Total Assets (boxplot)", "Households", "HouseholdsTotalAssetsDistro.png")
plot_time_series_mean_file(nHouseholds, nQuarters, HouseholdQuarterly$TOTAL_ASSETS, "Quarters", "Total Assests (mean)", "Households", "HouseholdsTotalAssetsMean.png")

boxplot_time_series_distro_file(nHouseholds, nQuarters, HouseholdQuarterly$HOUSING_VALUE, "Quarters", "Housing Value (boxplot)", "Households", "HouseholdsHousingValueDistro.png")
plot_time_series_mean_file(nHouseholds, nQuarters, HouseholdQuarterly$HOUSING_VALUE, "Quarters", "Housing Value (mean)", "Households", "HouseholdsHousingValueMean.png")

boxplot_time_series_distro_file(nHouseholds, nQuarters, HouseholdQuarterly$LIQUIDITY, "Quarters", "Household Liquidity (boxplot)", "Households", "HouseholdsLiquidityQuarterlyDistro.png")
plot_time_series_mean_file(nHouseholds, nQuarters, HouseholdQuarterly$LIQUIDITY, "Quarters", "Household Liquidity (mean)", "Households", "HouseholdsLiquidityQuarterlyMean.png")

boxplot_time_series_distro_file(nHouseholds, nQuarters, HouseholdQuarterly$EQUITY, "Quarters", "Equity (boxplot)", "Households", "HouseholdsEquityDistro.png")
plot_time_series_mean_file(nHouseholds, nQuarters, HouseholdQuarterly$EQUITY, "Quarters", "Equity (mean)", "Households", "HouseholdsEquityMean.png")

boxplot_time_series_distro_file(nHouseholds, nQuarters, HouseholdQuarterly$MORTGAGES, "Quarters", "Mortgages (boxplot)", "Households", "HouseholdsMortgagesDistro.png")
plot_time_series_mean_file(nHouseholds, nQuarters, HouseholdQuarterly$MORTGAGES, "Quarters", "Mortgages (mean)", "Households", "HouseholdsMortgagesMean.png")

boxplot_time_series_distro_file(nHouseholds, nQuarters, HouseholdQuarterly$LABOUR_INCOME, "Quarters", "Labour Income (boxplot)", "Households", "HouseholdsLabourIncomeDistro.png")
plot_time_series_mean_file(nHouseholds, nQuarters, HouseholdQuarterly$LABOUR_INCOME, "Quarters", "Labour Income (mean)", "Households", "HouseholdsLabourIncomeMean.png")

boxplot_time_series_distro_file(nHouseholds, nQuarters, HouseholdQuarterly$CAPITAL_INCOME, "Quarters", "Capital Income (boxplot)", "Households", "HouseholdsCapitalIncomeDistro.png")
plot_time_series_mean_file(nHouseholds, nQuarters, HouseholdQuarterly$CAPITAL_INCOME, "Quarters", "Capital Income (mean)", "Households", "HouseholdsCapitalIncomeMean.png")

boxplot_time_series_distro_file(nHouseholds, nQuarters, HouseholdQuarterly$HOUSING_PAYMENT, "Quarters", "Housing Payment (boxplot)", "Households", "HouseholdsHousingPaymentDistro.png")
plot_time_series_mean_file(nHouseholds, nQuarters, HouseholdQuarterly$HOUSING_PAYMENT, "Quarters", "Housing Payment (mean)", "Households", "HouseholdsHousingPaymentMean.png")

boxplot_time_series_distro_file(nHouseholds, nQuarters, HouseholdQuarterly$BENEFITS, "Quarters", "Total Benefits (boxplot)", "Households", "HouseholdsBenefitsDistro.png")
plot_time_series_mean_file(nHouseholds, nQuarters, HouseholdQuarterly$BENEFITS, "Quarters", "Total Benefits (mean)", "Households", "HouseholdsBenefitsMean.png")


#Household - Monthly
plot_time_series_mean_file(nHouseholds, nMonths, HouseholdMonthlyFirst$LIQUIDITY, "Months", "Liquidity (mean)", "Households", "HouseholdsLiquidityMonthly.png")
plot_time_series_mean_file(nHouseholds, nMonths, HouseholdMonthlyFirst$MORTGAGES, "Months", "Mortgages (mean)", "Households", "HouseholdsMortgagesMonthly.png")
plot_time_series_mean_file(nHouseholds, nMonths, HouseholdMonthlyFirst$MORTGAGE_COST, "Months", "Mortgage Costs (mean)", "Households", "HouseholdsMortgageCostsMonthly.png")
plot_time_series_mean_file(nHouseholds, nMonths, HouseholdMonthlyFirst$HOUSING_UNITS, "Months", "Housing Units (mean)", "Households", "HouseholdsHousingUnitsMonthly.png")
plot_time_series_mean_file(nHouseholds, nMonths, HouseholdMonthlyFirst$HOUSING_VALUE, "Months", "Housing Value (mean)", "Households", "HouseholdsHousingValuesMonthly.png")
plot_time_series_mean_file(nHouseholds, nMonths, HouseholdMonthlyFirst$EQUITY_RATIO, "Months", "Eqquity Ratio (mean)", "Households", "HouseholdsEquityRatioMonthly.png")


#Household - Weekly
plot_time_series_mean_file(nFirms, nWeeks, HouseholdWeekly$LIQUIDITY, "Weeks", "Liquidity (mean)", "Households", "HouseholdsLiquidityWeekly.png")
plot_time_series_mean_file(nHouseholds, nWeeks, HouseholdWeekly$money_to_spend, "Weeks", "Money Available to Spend (mean)", "Households", "HouseholdsMoneyToSpendWeekly.png")
plot_time_series_mean_file(nHouseholds, nWeeks, HouseholdWeekly$money_spent, "Weeks", "Money Spent (mean)", "Households", "HouseholdsMoneySpentWeekly.png")





###### Initialization Check ######
Firm_file = paste(data_dir, '/VV/', "Firm_ID_Liquidity_Loan.txt", sep ='')
HH_file = paste(data_dir, '/VV/', "Household_ID_Liquidity_Mortgages.txt", sep ='')
HH_init <- read.csv(HH_file, sep = " ", header = F, stringsAsFactors = F)
Firm_init <- read.csv(Firm_file, sep = " ", header = F, stringsAsFactors = F)

## Initial Deposits #
household_deposits <- sum(HH_init[[2]])
firm_deposits <- sum(Firm_init[[2]])
bank_deposits <- firm_deposits + household_deposits
sum(BankBalance$DEPOSITS[1:2])
bank_deposits

### Initial Mortgages ##
HHMortgagesInit <- sum(HH_init[[3]])
BankMortgagesInit <- sum(BankBalance$MORTGAGES[1:2])
HHMortgagesInit - BankMortgagesInit

### Initial Loans ##
FirmLoansInit <- sum(Firm_init[[3]])
BankLoansInit <- sum(BankBalance$LOANS[1:2])
BankLoansInit
FirmLoansInit



###### Flow of Housing Units :: New sales VS Total owned ####
HHLast <- sum(tail(HouseholdMonthlyFirst$HOUSING_UNITS, 800))
HHFirst <- sum(head(HouseholdMonthlyFirst$HOUSING_UNITS, 800))
new <- sum(CFirmMonthly$SALES) - sum(CFirmMonthly$SALES[1:3])
HHLast
HHFirst
new
HHLast - HHFirst

###### Flow of Consumption Goods :: Sales VS Buys ####
HHLast <- tail(HouseholdWeekly, 800 * 8)
head(HHLast)
tail(HHLast)
FirmLast <- tail(FirmMonthly,12)
FirmLast
HHPreLast <- sum(head(HHLast$quantity_bought, 800 * 4))
FirmLast <- sum(tail(FirmLast$SALES,12))
FirmLast
HHPreLast

#### Mortgages ####
HHMortgagesFirst <- sum(head(HouseholdQuarterly$MORTGAGES, 800))
BankMortgagesFirst <- sum(head(BankBalance$MORTGAGES,2))
HHMortgagesFirst - HHMortgagesInit
BankMortgagesFirst - HHMortgagesInit

HHMortgagesSecond <- sum(HouseholdQuarterly[801:1600,]$MORTGAGES)
BankMortgagesSecond <- sum(BankBalance[3:4,]$MORTGAGES)
BankMortgagesSecond - HHMortgagesSecond


head(tail(HouseholdQuarterly$MORTGAGES, 800))
tail(BankBalance$MORTGAGES,2)
sum(tail(BankBalance$MORTGAGES,2)) - sum(tail(HouseholdQuarterly$MORTGAGES, 800))


#### Loans :: Firms VS Banks ###

BankLoansFirst <- sum(BankBalance[1:2,]$LOANS)
BankLoansSecond <- sum(BankBalance[3:4,]$LOANS)
BankLoansLast <- sum(tail(BankBalance, 2)$LOANS)

CFirmLoanLastPre <- sum(head(tail(CFirmBalance, 6),3)$DEBT)
FirmLoanLastPre <- sum(head(tail(FirmBalance, 24),12)$DEBT)
FirmLoanLastPre + CFirmLoanLastPre

#### Debts :: Central Bank VS Banks and Governments ###
head(tail(Centralbank$LOANS_GOVERNMENT,2),1) - tail(Government$DEBT,1)
sum(tail(BankBalance$CENTRALBANK_DEBT, 2)) - tail(Centralbank$LOANS_BANKS,1)

# Taylors Rule:
indexed_prices <- (((Mall$AVG_GOODS_PRICE - Mall$AVG_GOODS_PRICE[1])/Mall$AVG_GOODS_PRICE) + 1)

infl_target <-  0.02
infl <- Centralbank$INFL
u <- Government$UNEMPLOYMENT_RATE
rcb <- infl + (infl - infl_target) * 0.5 - u * 0.5

CB <- Centralbank[1:3]
CB$taylor <- rcb
