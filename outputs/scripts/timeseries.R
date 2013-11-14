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


########## Single Run Anals #####

data_dir = "/Users/bulent/Documents/AWorkspace/iceace/FLAME/outputs/data"

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

file = paste(data_dir, '/', "Firm_Quarterly_IncomeStatement.txt", sep ='')
FirmIncome <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)

file = paste(data_dir, '/', "Firm_Quarterly_Dividends.txt", sep ='')
FirmDividends <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)

output_dir = "/Users/bulent/Documents/AWorkspace/iceace/FLAME/outputs/plots/"
setwd(output_dir)
nWeeks <- length(Mall$"IT_NO")
nMonths <- length(REAgency$"IT_NO")
nQuarters <- length(Equityfund$"IT_NO")
nFirms = length(FirmMonthly$"ID") / nMonths
nCFirms = length(CFirmMonthly$"ID") / nMonths
nBanks = length(BankIncome$"ID") / nQuarters
nIter <- nQuarters

HouseholdQuarterly <- read.csv('../data/Household_Quarterly.txt', sep = " ", header = T, stringsAsFactors = F)
HouseholdMonthlyFirst <- read.csv('../data/Household_Monthly_FirstDay.txt', sep = " ", header = T, stringsAsFactors = F)
HouseholdMonthlyLast <- read.csv('../data/Household_Monthly_LastDay.txt', sep = " ", header = T, stringsAsFactors = F)
HouseholdWeekly <- read.csv('../data/Household_Weekly.txt', sep = " ", header = T, stringsAsFactors = F)
nHouseholds = length(HouseholdQuarterly$"ID") / nQuarters


#MALL:
plot_time_series_point_file(nWeeks, Mall$AVG_GOODS_PRICE, "Weeks", "Average Unit Goods Price", "Consumption Goods Market", "AvgGoodsPrice.png")
plot_time_series_point_file(nWeeks, Mall$TRANSACTION_QUANTITY, "Weeks", "Number of Transactions", "Consumption Goods Market", "TransactionVolumeGoods.png")

#Real Estate Agency
plot_time_series_point_file(nMonths, REAgency$AVG_HOUSING_PRICE, "Months", "Average Unit Housing Price", "Real Estate Market", "AvgHousingPrice.png")
plot_time_series_point_file(nMonths, REAgency$TRANSACTION_QUANTITY, "Months", "Number of Housing Transactions", "Real Estate Market", "TransactionVolumeHouses.png")

#Central Bank
plot_time_series_point_file(nQuarters, Centralbank$INTEREST_RATE, "Quarters", "Interest Rate", "Central Bank", "InterestRate.png")
plot_time_series_point_file(nQuarters, Centralbank$INFLATION, "Quarters", "Inflation", "Central Bank", "Inflation.png")

#Government
plot_time_series_point_file(nQuarters, Government$UNEMPLOYMENT_RATE, "Quarters", "Unemployment Rate", "Government", "UnemploymentRate.png")
plot_time_series_point_file(nQuarters, Government$LABOUR_TAX_RATE, "Quarters", "Tax Rate (labour/Capital)", "Government", "TaxRate.png")
plot_time_series_point_file(nQuarters, Government$GOV_GENERAL_BENEFIT_RATE, "Quarters", "General Benefits Rate", "Government", "BenefitsRate.png")
plot_time_series_point_file(nQuarters, Government$UNEMPLOYMENT_BENEFITS, "Quarters", "Unemployment Benefits", "Government", "BenefitsUnemployment.png")
plot_time_series_point_file(nQuarters, Government$GENERAL_BENEFITS, "Quarters", "General Benefits", "Government", "BenefitsGeneral.png")

#Equity Fund
plot_time_series_point_file(nQuarters, Equityfund$DIVIDENDS_RECIEVED, "Quarters", "Dividends Received", "Equity Fund", "FundDividendsReceived.png")
plot_time_series_point_file(nQuarters, Equityfund$DIVIDENDS_RETAINED, "Quarters", "Dividends Retained", "Equity Fund", "FundDividendsRetained.png")
plot_time_series_point_file(nQuarters, Equityfund$LIQUIDITY, "Quarters", "Liquidity ", "Equity Fund", "FundLiquidity.png")

#Banks
plot_time_series_mean_file(nBanks, nQuarters, BankBalance$LOANS, "Quarters", "Loans to Firms (Mean)", "Banks", "Loans.png")
plot_time_series_mean_file(nBanks, nQuarters, BankBalance$MORTGAGES, "Quarters", "Mortgages to Households (Mean)", "Banks", "Mortgages.png")
plot_time_series_mean_file(nBanks, nQuarters, BankBalance$DEPOSITS, "Quarters", "Deposits from Firms, HH (Mean)", "Banks", "Deposits.png")
plot_time_series_mean_file(nBanks, nQuarters, BankBalance$CENTRALBANK_DEBT, "Quarters", "Central Bank Debt (Mean)", "Banks", "BanksDebt.png")
plot_time_series_mean_file(nBanks, nQuarters, BankBalance$EQUITY, "Quarters", "Equity (Mean)", "Banks", "BanksEquity.png")
plot_time_series_mean_file(nBanks, nQuarters, BankIncome$INTERESTS_ACCRUED, "Months", "Interests Collected (Mean)", "Banks", "BanksInterestsCollected.png")
plot_time_series_mean_file(nBanks, nQuarters, BankIncome$TOTAL_WRITEOFFS, "Quarters", "Total Writeoffs(Mean)", "Banks", "BanksWriteoffs.png")
plot_time_series_mean_file(nBanks, nQuarters, BankIncome$INTERESTS_PAID, "Months", "Interests Paid (Mean)", "Banks", "BanksInterestsPaid.png")
plot_time_series_mean_file(nBanks, nQuarters, BankIncome$NET_EARNINGS, "Months", "Net Earnings (Mean)", "Banks", "BanksNetEarnings.png")


#Firms
plot_time_series_mean_file(nFirms, nQuarters, FirmBalance$UNIT_GOODS_PRICE, "Quarters", "Price (mean)", "Firms", "FirmsUGPrices.png")

plot_time_series_mean_file(nFirms, nMonths, FirmMonthly$NO_EMPLOYEES, "Months", "No Employees (mean)", "Firms", "FirmsSize.png")
plot_time_series_mean_file(nFirms, nMonths, FirmMonthly$INVENTORY, "Months", "Inventory (mean)", "Firms", "FirmsInventory.png")
plot_time_series_mean_file(nFirms, nMonths, FirmMonthly$PRODUCTION_PLAN, "Months", "Production Plan (mean)", "Firms", "FirmsProductionPlan.png")
plot_time_series_mean_file(nFirms, nQuarters, FirmDividends$DIVIDENDS_PAID, "Quarters", "Dividends Paid (mean)", "Firms", "FirmsDividendsPaid.png")
plot_time_series_mean_file(nFirms, nQuarters, FirmIncome$REVENUES, "Quarters", "Sale Revenues (mean)", "Firms", "FirmsRevenues.png")
plot_time_series_mean_file(nFirms, nQuarters, FirmIncome$LABOUR_COSTS, "Quarters", "Labour Costs (mean)", "Firms", "FirmsLabourCosts.png")
plot_time_series_mean_file(nFirms, nQuarters, FirmIncome$TOTAL_INTEREST_PAYMENTS, "Quarters", "Interest Payments (mean)", "Firms", "FirmsInterestPayments.png")
plot_time_series_mean_file(nFirms, nQuarters, FirmIncome$NET_EARNINGS, "Quarters", "Net Earnings (mean)", "Firms", "FirmsNetEarnings.png")

plot_time_series_mean_file(nFirms, nQuarters, FirmBalance$TOTAL_ASSETS, "Quarters", "Total Assets (mean)", "Firms", "FirmsTotalAssets.png")
plot_time_series_mean_file(nFirms, nQuarters, FirmBalance$LIQUIDITY, "Quarters", "Liquidity (mean)", "Firms", "FirmsLiquidity.png")

plot_time_series_mean_file(nFirms, nQuarters, FirmBalance$EQUITY, "Quarters", "Equity (mean)", "Firms", "FirmsEquity.png")

plot_time_series_mean_file(nFirms, nQuarters, FirmBalance$DEBT, "Quarters", "Debt (mean)", "Firms", "FirmsDebt.png")
plot_time_series_mean_file(nFirms, nQuarters, FirmBalance$CAPITAL_GOODS, "Quarters", "Capital Goods (mean)", "Firms", "FirmsCapitalGoods.png")


#Household - Quarterly
boxplot_time_series_distro_file(nHouseholds, nQuarters, HouseholdQuarterly$HOUSING_VALUE, "Quarters", "Housing Value (boxplot)", "Households", "HouseholdsHousingValue.png")
boxplot_time_series_distro_file(nHouseholds, nQuarters, HouseholdQuarterly$LIQUIDITY, "Quarters", "Housing Liquidity (boxplot)", "Households", "HouseholdsLiquidityQuarterly.png")
boxplot_time_series_distro_file(nHouseholds, nQuarters, HouseholdQuarterly$CAPITAL_INCOME, "Quarters", "Capital Income (boxplot)", "Households", "HouseholdsCapitalIncome.png")
plot_time_series_mean_file(nHouseholds, nQuarters, HouseholdQuarterly$HOUSING_PAYMENT, "Quarters", "Housing Payment (boxplot)", "Households", "HouseholdsHousingPayment.png")

#Household - Monthly
plot_time_series_mean_file(nHouseholds, nMonths, HouseholdMonthlyFirst$LIQUIDITY, "Months", "Liquidity (mean)", "Households", "HouseholdsLiquidityMonthly.png")
plot_time_series_mean_file(nHouseholds, nMonths, HouseholdMonthlyFirst$MORTGAGES, "Months", "Mortgages (mean)", "Households", "HouseholdsMortgagesMonthly.png")
plot_time_series_mean_file(nHouseholds, nMonths, HouseholdMonthlyFirst$MORTGAGE_COST, "Months", "Mortgage Costs (mean)", "Households", "HouseholdsMortgageCostsMonthly.png")
plot_time_series_mean_file(nHouseholds, nMonths, HouseholdMonthlyFirst$HOUSING_UNITS, "Months", "Housing Units (mean)", "Households", "HouseholdsHousingUnits.png")


#Household - Weekly
boxplot_time_series_distro_file(nHouseholds, nWeeks, HouseholdWeekly$LIQUIDITY, "Weeks", "Liquidity (distro)", "Households", "HouseholdsLiquidityWeeklyDistro.png")
plot_time_series_mean_file(nFirms, nWeeks, HouseholdWeekly$LIQUIDITY, "Weeks", "Liquidity (mean)", "Households", "HouseholdsLiquidityWeekly.png")
boxplot_time_series_distro_file(nHouseholds, nWeeks, HouseholdWeekly$WEEKLY_CONSUMPTION_BUDGET, "Weeks", "Consumption Goods Budget (distro)", "Households", "HouseholdsConsumptionBudgetWeeklyDistro.png")
plot_time_series_mean_file(nHouseholds, nWeeks, HouseholdWeekly$WEEKLY_CONSUMPTION_BUDGET, "Weeks", "Consumption Goods Budget (mean)", "Households", "HouseholdsConsumptionBudgetWeekly.png")
plot_time_series_mean_file(nHouseholds, nWeeks, HouseholdWeekly$money_to_spend, "Weeks", "Money Available to Spend (mean)", "Households", "HouseholdsToSpendWeekly.png")
plot_time_series_mean_file(nHouseholds, nWeeks, HouseholdWeekly$money_spent, "Weeks", "Money Spent (mean)", "Households", "HouseholdsExpenditureWeekly.png")


########################## Experiments #######
output_dir = "/Users/bulent/Documents/AWorkspace/iceace/FLAME/outputs/plots/"
setwd(output_dir)
data_dir = "/Users/bulent/Documents/AWorkspace/iceace/FLAME/outputs/data/exps"
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

### Firms ####
# Revenues:
FirmIncomeSet <- get_experiment_data_set(data_dir, "Firm_Quarterly_IncomeStatement.txt")

revenue_set <- get_means_set(19, FirmIncomeSet, "REVENUES", nFirms, nQuarters)
boxplot_experiments(nQuarters, revenue_set)
boxplot_experiments_to_file(nQuarters, revenue_set, "Iterations (quarters)", "Amount", "Regular Firm Sale Revenues", "FirmsRevenues.png")

CFirmIncomeSet <- get_experiment_data_set(data_dir, "Constructor_Firm_Quarterly_IncomeStatement.txt")
crevenue_set <- get_means_set(19, CFirmIncomeSet, "REVENUES", nCFirms, nQuarters)
boxplot_experiments(nQuarters, crevenue_set)

# Size:
FirmMonthlySet <- get_experiment_data_set(data_dir, "Firm_Monthly.txt")
size_set <- get_means_set(19, FirmMonthlySet, "NO_EMPLOYEES", nFirms, nMonths)
boxplot_experiments(nMonths, size_set)
size_mean <- get_mean_of_experiments(nMonths, size_set)
plot_mean_experiments_to_file(nMonths, size_mean, "Iterations (months)", "Employee Number", "Regular Firm Size", "FirmsSize.png")



CFirmMonthlySet <- get_experiment_data_set(data_dir, "Constructor_Firm_Monthly.txt")
csize_set <- get_means_set(19, CFirmMonthlySet, "NO_EMPLOYEES", nCFirms, nMonths)
csize_mean <- get_mean_of_experiments(nMonths, csize_set)
plot_mean_experiments_to_file(nMonths, csize_mean, "Iterations (months)", "Employee Number", "Constructor Firm Size", "CFirmsSize.png")

FirmBalanceSet <- get_experiment_data_set(data_dir, "Firm_Quarterly_BalanceSheet.txt")
FirmMonthlySet <- get_experiment_data_set(data_dir, "Firm_Monthly.txt")
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



