time_series_boxplot <- function(nagents, niter, datavector, xlabel, ylabel, title, fname){
	png(fname, width = 800, height = 800, pointsize=24)
	times <- (1:niter)
	values <- matrix(datavector, nrow = niter, ncol = nagents, byrow = T)
	boxplot(values~times, type="l", xlab = xlabel, ylab=ylabel, main = title)
	dev.off()
}

time_series_mean <- function(nagents, niter, datavector, xlabel, ylabel, title, fname){
	png(fname, width = 800, height = 800, pointsize=24)
	times <- (1:niter)
	means <- (1:niter)
	values <- matrix(datavector, nrow = niter, ncol = nagents, byrow = T)
	for (i in 1:niter){
		means[i] <- mean(values[i,])
	}
	plot(means~times, type="l", xlab = xlabel, ylab=ylabel, main = title)
	dev.off()
}

time_series_point <- function(niter, datavector, xlabel, ylabel, title, fname){
	png(fname, width = 800, height = 800, pointsize=24)
	times <- (1:niter)
	plot(datavector~times, type="l", xlab = xlabel, ylab=ylabel, main = title)
	dev.off()
}


setwd("/Users/bulent/Documents/AWorkspace/iceace/FLAME/outputs/plots/")

Government <- read.csv('../data/Government_snapshot.txt', sep = " ", header = T, stringsAsFactors = F)
Centralbank <- read.csv('../data/CentralBank_snapshot.txt', sep = " ", header = T, stringsAsFactors = F)
Equityfund <- read.csv('../data/EquityFund_snapshot.txt', sep = " ", header = T, stringsAsFactors = F)
Mall <- read.csv('../data/Mall_snapshot.txt', sep = " ", header = T, stringsAsFactors = F)
REAgency<- read.csv('../data/REAgency_snapshot.txt', sep = " ", header = T, stringsAsFactors = F)


nWeeks <- length(Mall$IT_NO)
nMonths <- length(REAgency$IT_NO)
nQuarters <- length(Equityfund$IT_NO)
nFirms = 150
nHouseholds = 8000
nBanks = 2

BankBalance <- read.csv('../data/Bank_BalanceSheet.txt', sep = " ", header = T, stringsAsFactors = F)
BankIncome <- read.csv('../data/Bank_IncomeStatement.txt', sep = " ", header = T, stringsAsFactors = F)

FirmMonthly <- read.csv('../data/Firm_Monthly.txt', sep = " ", header = T, stringsAsFactors = F)
FirmBalance <- read.csv('../data/Firm_Quarterly_BalanceSheet.txt', sep = " ", header = T, stringsAsFactors = F)
FirmIncome <- read.csv('../data/Firm_Quarterly_IncomeStatement.txt', sep = " ", header = T, stringsAsFactors = F)
FirmDividends <- read.csv('../data/Firm_Quarterly_Dividends.txt', sep = " ", header = T, stringsAsFactors = F)

HouseholdQuarterly <- read.csv('../data/Household_Quarterly.txt', sep = " ", header = T, stringsAsFactors = F)
HouseholdWeekly <- read.csv('../data/Household_Weekly.txt', sep = " ", header = T, stringsAsFactors = F)
HouseholdMonthlyFirst <- read.csv('../data/Household_Monthly_FirstDay.txt', sep = " ", header = T, stringsAsFactors = F)
HouseholdMonthlyLast <- read.csv('../data/Household_Monthly_LastDay.txt', sep = " ", header = T, stringsAsFactors = F)

#MALL:
time_series_mean(1, nWeeks, Mall$AVG_GOODS_PRICE, "Weeks", "Average Unit Goods Price", "Consumption Goods Market", "AvgGoodsPrice.png")
time_series_point(nWeeks, Mall$TRANSACTION_QUANTITY, "Weeks", "Number of Transactions", "Consumption Goods Market", "TransactionVolumeGoods.png")

#Real Estate Agency
time_series_point(nMonths, REAgency$AVG_HOUSING_PRICE, "Months", "Average Unit Housing Price", "Real Estate Market", "AvgHousingPrice.png")
time_series_point(nMonths, REAgency$TRANSACTION_QUANTITY, "Months", "Number of Housing Transactions", "Real Estate Market", "TransactionVolumeHouses.png")

#Central Bank
time_series_point(nQuarters, Centralbank$INTEREST_RATE, "Quarters", "Interest Rate", "Central Bank", "InterestRate.png")
time_series_point(nQuarters, Centralbank$INFLATION, "Quarters", "Inflation", "Central Bank", "Inflation.png")

#Government
time_series_point(nQuarters, Government$UNEMPLOYMENT_RATE, "Quarters", "Unemployment Rate", "Government", "UnemploymentRate.png")
time_series_point(nQuarters, Government$LABOUR_TAX_RATE, "Quarters", "Tax Rate (labour/Capital)", "Government", "TaxRate.png")
time_series_point(nQuarters, Government$GOV_GENERAL_BENEFIT_RATE, "Quarters", "General Benefits Rate", "Government", "BenefitsRate.png")
time_series_point(nQuarters, Government$UNEMPLOYMENT_BENEFITS, "Quarters", "Unemployment Benefits", "Government", "BenefitsUnemployment.png")
time_series_point(nQuarters, Government$GENERAL_BENEFITS, "Quarters", "General Benefits", "Government", "BenefitsGeneral.png")

#Equity Fund
time_series_point(nQuarters, Equityfund$DIVIDENDS_RECIEVED, "Quarters", "Dividends Received", "Equity Fund", "FundDividendsReceived.png")
time_series_point(nQuarters, Equityfund$DIVIDENDS_RETAINED, "Quarters", "Dividends Retained", "Equity Fund", "FundDividendsRetained.png")
time_series_point(nQuarters, Equityfund$LIQUIDITY, "Quarters", "Liquidity ", "Equity Fund", "FundLiquidity.png")

#Banks
time_series_mean(nBanks, nQuarters, BankBalance$LOANS, "Quarters", "Loans to Firms (Mean)", "Banks", "Loans.png")
time_series_mean(nBanks, nQuarters, BankBalance$MORTGAGES, "Quarters", "Mortgages to Households (Mean)", "Banks", "Mortgages.png")
time_series_mean(nBanks, nQuarters, BankBalance$DEPOSITS, "Quarters", "Deposits from Firms, HH (Mean)", "Banks", "Deposits.png")
time_series_mean(nBanks, nQuarters, BankBalance$CENTRALBANK_DEBT, "Quarters", "Central Bank Debt (Mean)", "Banks", "BanksDebt.png")
time_series_mean(nBanks, nQuarters, BankBalance$EQUITY, "Quarters", "Equity (Mean)", "Banks", "BanksEquity.png")
time_series_mean(nBanks, nQuarters, BankIncome$INTERESTS_ACCRUED, "Months", "Interests Collected (Mean)", "Banks", "BanksInterestsCollected.png")
time_series_mean(nBanks, nQuarters, BankIncome$TOTAL_WRITEOFFS, "Quarters", "Total Writeoffs(Mean)", "Banks", "BanksWriteoffs.png")
time_series_mean(nBanks, nQuarters, BankIncome$INTERESTS_PAID, "Months", "Interests Paid (Mean)", "Banks", "BanksInterestsPaid.png")
time_series_mean(nBanks, nQuarters, BankIncome$NET_EARNINGS, "Months", "Net Earnings (Mean)", "Banks", "BanksNetEarnings.png")


#Firms
time_series_mean(nFirms, nMonths, FirmMonthly$NO_EMPLOYEES, "Months", "No Employees (mean)", "Firms", "FirmsSize.png")
time_series_mean(nFirms, nMonths, FirmMonthly$INVENTORY, "Months", "Inventory (mean)", "Firms", "FirmsInventory.png")
time_series_mean(nFirms, nMonths, FirmMonthly$PRODUCTION_PLAN, "Months", "Production Plan (mean)", "Firms", "FirmsProductionPlan.png")
time_series_mean(nFirms, nQuarters, FirmDividends$DIVIDENDS_PAID, "Quarters", "Dividends Paid (mean)", "Firms", "FirmsDividendsPaid.png")
time_series_mean(nFirms, nQuarters, FirmIncome$REVENUES, "Quarters", "Sale Revenues (mean)", "Firms", "FirmsRevenues.png")
time_series_mean(nFirms, nQuarters, FirmIncome$LABOUR_COSTS, "Quarters", "Labour Costs (mean)", "Firms", "FirmsLabourCosts.png")
time_series_mean(nFirms, nQuarters, FirmIncome$TOTAL_INTEREST_PAYMENTS, "Quarters", "Interest Payments (mean)", "Firms", "FirmsInterestPayments.png")
time_series_mean(nFirms, nQuarters, FirmIncome$NET_EARNINGS, "Quarters", "Net Earnings (mean)", "Firms", "FirmsNetEarnings.png")

time_series_mean(nFirms, nQuarters, FirmBalance$TOTAL_ASSETS, "Quarters", "Total Assets (mean)", "Firms", "FirmsTotalAssets.png")
time_series_mean(nFirms, nQuarters, FirmBalance$LIQUIDITY, "Quarters", "Liquidity (mean)", "Firms", "FirmsLiquidity.png")
time_series_mean(nFirms, nQuarters, FirmBalance$DEBT, "Quarters", "Debt (mean)", "Firms", "FirmsDebt.png")
time_series_mean(nFirms, nQuarters, FirmBalance$CAPITAL_GOODS, "Quarters", "Capital Goods (mean)", "Firms", "FirmsCapitalGoods.png")


#Household - Quarterly
time_series_boxplot(nHouseholds, nQuarters, HouseholdQuarterly$HOUSING_VALUE, "Quarters", "Housing Value (boxplot)", "Households", "HouseholdsHousingValue.png")
time_series_boxplot(nHouseholds, nQuarters, HouseholdQuarterly$LIQUIDITY, "Quarters", "Housing Liquidity (boxplot)", "Households", "HouseholdsLiquidityQuarterly.png")
time_series_boxplot(nHouseholds, nQuarters, HouseholdQuarterly$CAPITAL_INCOME, "Quarters", "Capital Income (boxplot)", "Households", "HouseholdsCapitalIncome.png")
time_series_boxplot(nHouseholds, nQuarters, HouseholdQuarterly$HOUSING_PAYMENT, "Quarters", "Housing Payment (boxplot)", "Households", "HouseholdsHousingPayment.png")

#Household - Monthly
time_series_mean(nHouseholds, nMonths, HouseholdMonthlyFirst$LIQUIDITY, "Months", "Liquidity (mean)", "Households", "HouseholdsLiquidityMonthly.png")
time_series_mean(nHouseholds, nMonths, HouseholdMonthlyFirst$MORTGAGES, "Months", "Mortgages (mean)", "Households", "HouseholdsMortgagesMonthly.png")
time_series_mean(nHouseholds, nMonths, HouseholdMonthlyFirst$MORTGAGE_COST, "Months", "Mortgage Costs (mean)", "Households", "HouseholdsMortgageCostsMonthly.png")
time_series_mean(nHouseholds, nMonths, HouseholdMonthlyFirst$HOUSING_UNITS, "Months", "Housing Units (mean)", "Households", "HouseholdsHousingUnits.png")


#Household - Weekly
time_series_boxplot(nHouseholds, nWeeks, HouseholdWeekly$LIQUIDITY, "Weeks", "Liquidity (distro)", "Households", "HouseholdsLiquidityWeeklyDistro.png")
time_series_mean(nFirms, nWeeks, HouseholdWeekly$LIQUIDITY, "Weeks", "Liquidity (mean)", "Households", "HouseholdsLiquidityWeekly.png")
time_series_boxplot(nHouseholds, nWeeks, HouseholdWeekly$WEEKLY_CONSUMPTION_BUDGET, "Weeks", "Consumption Goods Budget (distro)", "Households", "HouseholdsConsumptionBudgetWeeklyDistro.png")
time_series_mean(nHouseholds, nWeeks, HouseholdWeekly$WEEKLY_CONSUMPTION_BUDGET, "Weeks", "Consumption Goods Budget (mean)", "Households", "HouseholdsConsumptionBudgetWeekly.png")
time_series_mean(nHouseholds, nWeeks, HouseholdWeekly$money_to_spend, "Weeks", "Money Available to Spend (mean)", "Households", "HouseholdsToSpendWeekly.png")
time_series_mean(nHouseholds, nWeeks, HouseholdWeekly$money_spent, "Weeks", "Money Spent (mean)", "Households", "HouseholdsExpenditureWeekly.png")


