time_series_boxplot <- function(nagents, niter, datavector){
	times <- (1:niter)
	values <- matrix(datavector, nrow = niter, ncol = nagents, byrow = T)
	boxplot(values~times)
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

png("Bk-merged.png", width = 800, height = 800, pointsize=24)

setwd("/Users/bulent/Documents/AWorkspace/iceace/FLAME/outputs/plots")

Government <- read.csv('../data/Government_snapshot.txt', sep = " ", header = T, stringsAsFactors = F)
Centralbank <- read.csv('../data/CentralBank_snapshot.txt', sep = " ", header = T, stringsAsFactors = F)
Equityfund <- read.csv('../data/EquityFund_snapshot.txt', sep = " ", header = T, stringsAsFactors = F)
Mall <- read.csv('../data/Mall_snapshot.txt', sep = " ", header = T, stringsAsFactors = F)
REAgency<- read.csv('../data/REAgency_snapshot.txt', sep = " ", header = T, stringsAsFactors = F)

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

nWeeks <- length(Mall$IT_NO)
nMonths <- length(REAgency$IT_NO)
nQuarters <- length(Equityfund$IT_NO)
nFirms = 15
nHouseholds = 800
nBanks = 2


plot(1,type='n',xlim=c(1,nQuarters),ylim=c(0,max(Government$UNEMPLOYMENT_RATE)),xlab='Quarters', ylab='Rates')

time_series_point(nMonths, Government$UNEMPLOYMENT_RATE)
time_series_boxplot(nHouseholds, nIter, Household$LIQUIDITY)
#time_series_mean(nHouseholds, nIter, Household$LIQUIDITY)
#


