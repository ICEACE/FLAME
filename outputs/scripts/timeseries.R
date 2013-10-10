time_series_boxplot <- function(nagents, niter, datavector){
	times <- (1:niter)
	values <- matrix(datavector, nrow = niter, ncol = nagents, byrow = T)
	boxplot(values~times)
}

time_series_mean <- function(nagents, niter, datavector){
	times <- (1:niter)
	means <- (1:niter)
	values <- matrix(datavector, nrow = niter, ncol = nagents, byrow = T)
	for (i in 1:niter){
		means[i] <- mean(values[i,])
	}
	plot(means~times)
}

time_series_point <- function(niter, datavector){
	times <- (1:niter)
	plot(datavector~times)
}


Government <- read.csv('../data/Government_snapshot.txt', sep = " ", header = T, stringsAsFactors = F)
Centralbank <- read.csv('../data/CentralBank_snapshot.txt', sep = " ", header = T, stringsAsFactors = F)
Equityfund <- read.csv('../data/EquityFund_snapshot.txt', sep = " ", header = T, stringsAsFactors = F)
Bank <- read.csv('../data/Bank_snapshot.txt', sep = " ", header = T, stringsAsFactors = F)
Firm <- read.csv('../data/Firm_snapshot.txt', sep = " ", header = T, stringsAsFactors = F)
Household <- read.csv('../data/Household_snapshot.txt', sep = " ", header = T, stringsAsFactors = F)

nIter <- max(Government$IT_NO)
nFirms <- length(Firm$IT_NO) / nIter
nHouseholds <- length(Household$IT_NO) / nIter
nBanks <- length(Bank$IT_NO) / nIter

time_series_boxplot(nHouseholds, nIter, Household$LIQUIDITY)
time_series_mean(nHouseholds, nIter, Household$LIQUIDITY)
time_series_point(nIter, Government$UNEMPLOYMENT_RATE)


