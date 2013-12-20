# Importing Datasets #

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

if (data_household){
	HouseholdQuarterly <- read.csv('../data/Household_Quarterly.txt', sep = " ", header = T, stringsAsFactors = F)
	HouseholdMonthlyFirst <- read.csv('../data/Household_Monthly_FirstDay.txt', sep = " ", header = T, stringsAsFactors = F)
	HouseholdMonthlyLast <- read.csv('../data/Household_Monthly_LastDay.txt', sep = " ", header = T, stringsAsFactors = F)
	HouseholdWeekly <- read.csv('../data/Household_Weekly.txt', sep = " ", header = T, stringsAsFactors = F)
	nHouseholds = length(HouseholdQuarterly$"ID") / nQuarters
}
