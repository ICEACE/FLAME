boxplot_time_series_distro_file <- function(nagents, niter, datavector, xlabel, ylabel, title, fname){
	png(fname, width = 800, height = 800, pointsize=24)
	times <- (1:niter)
	values <- matrix(datavector, nrow = niter, ncol = nagents, byrow = T)
	boxplot(values~times, type="l", xlab = xlabel, ylab=ylabel, main = title)
	dev.off()
}

boxplot_experiments_to_file <- function(niter, exps, xlabel, ylabel, title, fname){
	png(fname, width = 800, height = 800, pointsize=24)
	iters <- (1:niter)
	boxplot(exps~iters, type="l", xlab = xlabel, ylab=ylabel, main = title)
	dev.off()
}


plot_mean_experiments_to_file <- function(niter, exps, xlabel, ylabel, title, fname){
	png(fname, width = 800, height = 800, pointsize=24)
	iters <- (1:niter)
	plot(exps~iters, type="l", xlab = xlabel, ylab=ylabel, main = title)
	dev.off()
}


plot_time_series_mean_file <- function(nagents, niter, datavector, xlabel, ylabel, title, fname){
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

plot_time_series_point_file <- function(niter, datavector, xlabel, ylabel, title, fname){
	png(fname, width = 800, height = 800, pointsize=24)
	times <- (1:niter)
	plot(datavector~times, type="l", xlab = xlabel, ylab=ylabel, main = title)
	dev.off()
}

get_experiment_data_set <-function(data_dir, data_file){
	exps <- list.files(data_dir)
	n_exps <- length(exps)
	dataSet <- list()
	for (i in 1:n_exps){
		filename = paste(data_dir,list.files(data_dir)[i], '/', data_file, sep ='')
		dataSet[[i]] <- read.csv(filename, sep = " ", header = T, stringsAsFactors = F)
	}
	return(dataSet)
}

get_points_set <- function(nexps, dataSet, memVar){
	means <- dataSet[[1]][memVar]
	if (nexps < 2){
		return(means)
		}
	for (i in 2:nexps){
		means <- cbind(means, dataSet[[i]][memVar]) 
	}
	return(as.matrix(means))
}

get_mean_of_experiments <- function(niters, datamatrix){
	times <- (1:niters)
	mean <- (1:niters)
	for (i in 1:niters){
		mean[i] <- mean(datamatrix[i,]) 
	}
	return(mean)
}

plot_mean_experiments <- function(niter, exps){
	iters <- (1:niter)
	plot(exps~iters, type="l")
}

boxplot_experiments <- function(niter, exps){
	iters <- (1:niter)
	boxplot(exps~iters, type="l")
}

get_means <- function(nagents, niter, datavector){
	times <- (1:niter)
	means <- (1:niter)
	values <- matrix(datavector, nrow = niter, ncol = nagents, byrow = T)
	for (i in 1:niter){
		means[i] <- mean(values[i,])
	}
	return(means)
}

get_means_set <- function(nexps, dataSet, memVar, nagents, niter){
	means <- get_means(nagents, niter, dataSet[[1]][memVar][,1])
	if (nexps < 2){
		return(as.matrix(means))
		}	
	meansSet = means
	for (i in 2:nexps){
		means <- get_means(nagents, niter, dataSet[[i]][memVar][,1])
		meansSet <- cbind(meansSet, means) 
	}
	return(as.matrix(meansSet))
}

output_dir = "/Users/bulent/Documents/AWorkspace/iceace/FLAME/outputs/plots/"
setwd(output_dir)
data_dir = "/Users/bulent/Documents/AWorkspace/iceace/FLAME/outputs/data/exps/"
exps <- list.files(data_dir)
n_exps <- length(exps)

GovernmentSet <- get_experiment_data_set(data_dir, "Government_snapshot.txt")
CentralbankSet <- get_experiment_data_set(data_dir, "CentralBank_snapshot.txt")
EquityfundSet <- get_experiment_data_set(data_dir, "EquityFund_snapshot.txt")
MallSet <- get_experiment_data_set(data_dir, "Mall_snapshot.txt")
REAgencySet <- get_experiment_data_set(data_dir, "REAgency_snapshot.txt")

nWeeks <- length(MallSet[[1]]$"IT_NO")
nMonths <- length(REAgencySet[[1]]$"IT_NO")
nQuarters <- length(EquityfundSet[[1]]$"IT_NO")
nFirms = 120
nCFirms = 30
nHouseholds = 8000
nBanks = 2


nIter <- nQuarters

### Government #####
# Unemployment:
unemployment_set <- get_points_set(n_exps, GovernmentSet, "UNEMPLOYMENT_RATE")
boxplot_experiments(nIter, unemployment_set)
boxplot_experiments_to_file(nIter, unemployment_set, "Iterations (quarters)", "Unemployment Rate", "", "UnemploymentRate.png")
unemployment_mean <- get_mean_of_experiments(nIter, unemployment_set)
plot_mean_experiments(nIter, unemployment_mean)

#Benefits:
benefitgeneral_set <- get_points_set(n_exps, GovernmentSet, "GENERAL_BENEFITS")
benefitgeneral_mean <- get_mean_of_experiments(nIter, benefitgeneral_set)
plot_mean_experiments(nIter, benefitgeneral_mean)
plot_mean_experiments_to_file(nIter, benefitgeneral_mean, "Iterations (quarters)", "Amount", "Government General Benefits", "BenefitsGeneral.png")
benefitunemployment_set <- get_points_set(n_exps, GovernmentSet, "UNEMPLOYMENT_BENEFITS")
boxplot_experiments(nIter, benefitunemployment_set)
boxplot_experiments_to_file(nIter, benefitunemployment_set, "Iterations (quarters)", "Amount", "Government Unemployment Benefits", "BenefitsUnemployment.png")

### Central Bank ###
# Inflation:
inflation_set <- get_points_set(n_exps, CentralbankSet, "INFLATION_RATE")
inflation_mean <- get_mean_of_experiments(nIter, inflation_set)
plot_mean_experiments_to_file(nIter, inflation_mean, "Iterations (quarters)", "Rate", "Inflation", "Inflation.png")
# Interest Rate:
interest_set <- get_points_set(n_exps, CentralbankSet, "INTEREST_RATE")
interest_mean <- get_mean_of_experiments(nIter, interest_set)
plot_mean_experiments_to_file(nIter, interest_mean, "Iterations (quarters)", "Rate", "Central Bank Interest Rates", "InterestRate.png")

### Mall ###
# Prices:
goodsprice_set <- get_points_set(n_exps, MallSet, "AVG_GOODS_PRICE")
boxplot_experiments(nWeeks, goodsprice_set)
goodsprices_mean <- get_mean_of_experiments(nWeeks, goodsprice_set)
plot_mean_experiments_to_file(nWeeks, goodsprices_mean, "Iterations (weeks)", "Unit Price", "Average Goods Prices", "AvgGoodsPrice.png")
# Transaction Volume:
transactiongoods_set <- get_points_set(n_exps, MallSet, "TRANSACTION_QUANTITY")
boxplot_experiments(nWeeks, transactiongoods_set)
transactiongoods_mean <- get_mean_of_experiments(nWeeks, transactiongoods_set)
plot_mean_experiments_to_file(nWeeks, transactiongoods_mean, "Iterations (weeks)", "Quantity", "Weekly Consumption Goods Sales", "TransactionVolumeGoods.png")

### REAgency ###
# Transaction Volume:
transactionhouses_set <- get_points_set(n_exps, REAgencySet, "TRANSACTION_QUANTITY")
boxplot_experiments(nMonths, transactionhouses_set)
transactionhouses_mean <- get_mean_of_experiments(nMonths, transactionhouses_set)
plot_mean_experiments_to_file(nMonths, transactionhouses_mean, "Iterations (months)", "Quantity", "Monthly Housing Unit Sales", "TransactionVolumeHouses.png")

### Banks ###
BankBalanceSet <- get_experiment_data_set(data_dir, "Bank_BalanceSheet.txt")
BankIncomeSet <- get_experiment_data_set(data_dir, "Bank_IncomeStatement.txt")

# Loans:
loans_set <- get_means_set(n_exps, BankBalanceSet, "LOANS", nBanks, nQuarters)
boxplot_experiments(nQuarters, loans_set)
boxplot_experiments_to_file(nQuarters, loans_set, "Iterations (quarters)", "Amount", "Bank Loan Assets", "Loans.png")

# Mortgages:
mortgages_set <- get_means_set(n_exps, BankBalanceSet, "MORTGAGES", nBanks, nQuarters)
boxplot_experiments(nQuarters, mortgages_set)
boxplot_experiments_to_file(nQuarters, mortgages_set, "Iterations (quarters)", "Amount", "Bank Mortgage Assets", "Mortgages.png")

# Writeoffs:
writeoff_set <- get_means_set(n_exps, BankIncomeSet, "TOTAL_WRITEOFFS", nBanks, nQuarters)
boxplot_experiments(nQuarters, writeoff_set)
boxplot_experiments_to_file(nQuarters, writeoff_set, "Iterations (quarters)", "Amount", "Bank Total Writeoffs", "BanksWriteoffs.png")

bankrevenues_mean <- get_mean_of_experiments(nQuarters, bankrevenues_set)
plot_mean_experiments(nQuarters, bankrevenues_mean)

FirmMonthlySet <- get_experiment_data_set(data_dir, "Firm_Monthly.txt")
FirmBalanceSet <- get_experiment_data_set(data_dir, "Firm_Quarterly_BalanceSheet.txt")
FirmIncomeSet <- get_experiment_data_set(data_dir, "Firm_Quarterly_IncomeStatement.txt")
FirmDividendsSet <- get_experiment_data_set(data_dir, "Firm_Quarterly_Dividends.txt")

CFirmMonthlySet <- get_experiment_data_set(data_dir, "Constructor_Firm_Monthly.txt")
CFirmBalanceSet <- get_experiment_data_set(data_dir, "Constructor_Firm_Quarterly_BalanceSheet.txt")
CFirmIncomeSet <- get_experiment_data_set(data_dir, "Constructor_Firm_Quarterly_IncomeStatement.txt")
CFirmDividendsSet <- get_experiment_data_set(data_dir, "Constructor_Firm_Quarterly_Dividends.txt")


cfirmdividendspaid_set <- get_means_set(n_exps, CFirmDividendsSet, "DIVIDENDS_PAID", nCFirms, nQuarters)
boxplot_experiments(nQuarters,cfirmdividendspaid_set)
cfirmdividendspaid_mean <- get_mean_of_experiments(nQuarters, cfirmdividendspaid_set)
plot_mean_experiments(nQuarters, cfirmdividendspaid_mean)


cfirmsize_set <- get_means_set(n_exps, CFirmMonthlySet, "NO_EMPLOYEES", nCFirms, nMonths)
boxplot_experiments(nMonths,cfirmsize_set)
cfirmsize_mean <- get_mean_of_experiments(nMonths, cfirmsize_set)
plot_mean_experiments(nMonths, cfirmsize_mean)

firmsize_set <- get_means_set(n_exps, FirmMonthlySet, "NO_EMPLOYEES", nFirms, nMonths)
boxplot_experiments(nMonths,firmsize_set)
firmsize_mean <- get_mean_of_experiments(nMonths, firmsize_set)
plot_mean_experiments(nMonths, firmsize_mean)

HouseholdQuarterlySet <- get_experiment_data_set(data_dir, "Household_Quarterly.txt")


Government <- read.csv('../data/anals/Government_snapshot.txt', sep = " ", header = T, stringsAsFactors = F)
Centralbank <- read.csv('../data/anals/CentralBank_snapshot.txt', sep = " ", header = T, stringsAsFactors = F)
Equityfund <- read.csv('../data/anals/EquityFund_snapshot.txt', sep = " ", header = T, stringsAsFactors = F)
Mall <- read.csv('../data/anals/Mall_snapshot.txt', sep = " ", header = T, stringsAsFactors = F)
REAgency <- read.csv('../data/anals/REAgency_snapshot.txt', sep = " ", header = T, stringsAsFactors = F)


BankBalance <- read.csv('../data/anals/Bank_BalanceSheet.txt', sep = " ", header = T, stringsAsFactors = F)
BankIncome <- read.csv('../data/anals/Bank_IncomeStatement.txt', sep = " ", header = T, stringsAsFactors = F)

FirmMonthly <- read.csv('../data/anals/Firm_Monthly.txt', sep = " ", header = T, stringsAsFactors = F)
FirmBalance <- read.csv('../data/anals/Firm_Quarterly_BalanceSheet.txt', sep = " ", header = T, stringsAsFactors = F)
FirmIncome <- read.csv('../data/anals/Firm_Quarterly_IncomeStatement.txt', sep = " ", header = T, stringsAsFactors = F)
FirmDividends <- read.csv('../data/anals/Firm_Quarterly_Dividends.txt', sep = " ", header = T, stringsAsFactors = F)

HouseholdQuarterly <- read.csv('../data/anals/Household_Quarterly.txt', sep = " ", header = T, stringsAsFactors = F)
HouseholdMonthlyFirst <- read.csv('../data/anals/Household_Monthly_FirstDay.txt', sep = " ", header = T, stringsAsFactors = F)
HouseholdMonthlyLast <- read.csv('../data/anals/Household_Monthly_LastDay.txt', sep = " ", header = T, stringsAsFactors = F)
HouseholdWeekly <- read.csv('../data/anals/Household_Weekly.txt', sep = " ", header = T, stringsAsFactors = F)

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


