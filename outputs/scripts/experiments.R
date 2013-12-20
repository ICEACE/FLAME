


########################## Experiments : Based on 20 random seeds and full population run #######
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