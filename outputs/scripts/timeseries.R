boxplot_time_series_distro_file <- function(nagents, niter, datavector, xlabel, ylabel, title, fname){
	png(fname, width = 1500, height = 800, pointsize=24)
	times <- (1:niter)
	values <- matrix(datavector, nrow = niter, ncol = nagents, byrow = T)
	boxplot(values~times, type="l", col = "blue", lwd = 3, xlab = xlabel, ylab=ylabel, main = title)
	dev.off()
}

boxplot_experiments_to_file <- function(niter, exps, xlabel, ylabel, title, fname){
	png(fname, width = 1500, height = 800, pointsize=24)
	iters <- (1:niter)
	boxplot(exps~iters, type="l", col = "blue", lwd = 3, xlab = xlabel, ylab=ylabel, main = title)
	dev.off()
}


plot_mean_experiments_to_file <- function(niter, exps, xlabel, ylabel, title, fname){
	png(fname, width = 1500, height = 800, pointsize=24)
	iters <- (1:niter)
	plot(exps~iters, type="l", col = "blue", lwd = 3, xlab = xlabel, ylab=ylabel, main = title)
	dev.off()
}


plot_time_series_mean_file <- function(nagents, niter, datavector, xlabel, ylabel, title, fname){
	png(fname, width = 1500, height = 800, pointsize=24)
	times <- (1:niter)
	means <- (1:niter)
	values <- matrix(datavector, nrow = niter, ncol = nagents, byrow = T)
	for (i in 1:niter){
		means[i] <- mean(values[i,])
	}
	plot(means~times, type="l", col = "blue", lwd = 3, xlab = xlabel, ylab=ylabel, main = title)
	dev.off()
}

plot_time_series_mean_file_v2 <- function(niter, itervector, memoryvector, xlabel, ylabel, title, fname){
	times <- (1:niter)
	means <- (1:niter)
	current_iter <- itervector[1]
	datalength <- length(memoryvector)
	accumulator <- 0
	nvals <- 0
	ind <- 1
	for (i in 1:datalength){
		if (itervector[i] != current_iter){
			means[ind] <- accumulator / nvals
			ind <- ind + 1
			nvals <- 0
			accumulator <- 0
			current_iter <- itervector[i]	
		}
		nvals <- nvals + 1
		accumulator <- accumulator + memoryvector[i]
	}
	means[ind] <- accumulator / nvals
	png(fname, width = 1500, height = 800, pointsize=24)
	plot(means~times, type="l", col = "blue", lwd = 3, xlab = xlabel, ylab=ylabel, main = title)
	dev.off()
}


plot_time_series_point_file <- function(niter, datavector, xlabel, ylabel, title, fname){
	png(fname, width = 1500, height = 800, pointsize=24)
	times <- (1:niter)
	plot(datavector~times, type="l", col = "blue", lwd = 3, xlab = xlabel, ylab=ylabel, main = title)
	dev.off()
}

plot_time_series_multiline_point_file <- function(niter, v1, v2, v3=vector(), xlabel, ylabel, title, fname, legends){
	times <- (1:niter)
	valrange <- v1
	valrange[1] <- min(c(v1,v2,v3))
	valrange[-1] <- max(c(v1,v2,v3))
	png(fname, width = 1500, height = 800, pointsize=18)
	plot(valrange~times, type="n", xlab = xlabel, ylab=ylabel, main = title)
	lines(v1~times, type="l", col="red", lwd=3)
	lines(v2~times, type="l", col="blue", lwd=3)
	if (length(v3) > 1){
		lines(v3~times, type="l", col="black", lwd=3)	
		legend("topleft", legends, lty = c(1,1,1), lwd = c(2,2,2), col = c("red", "blue", "black"))
	}
	else{
		legend("topleft", legends, lty = c(1,1), lwd = c(2,2), col = c("red", "blue"))
		}
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



plot_gdp_to_file_v1 <- function(niter, firmiters, firmvector, cfirmiters, cfirmvector, gtype = "Nominal"){
	times <- (1:niter)
	fsums <- (1:niter)
	csums <- (1:niter)
	gdp <- (1:niter)
	
	#Regular Firm productions
	current_iter <- firmiters[1]
	datalength <- length(firmvector)
	accumulator <- 0
	ind <- 1
	for (i in 1:datalength){
		if (firmiters[i] != current_iter){
			fsums[ind] <- accumulator
			ind <- ind + 1
			accumulator <- 0
			current_iter <- firmiters[i]	
		}
		accumulator <- accumulator + firmvector[i]
	}
	fsums[ind] <- accumulator

    #constructor Firm productions
	current_iter <- cfirmiters[1]
	datalength <- length(cfirmvector)
	accumulator <- 0
	ind <- 1
	for (i in 1:datalength){
		if (cfirmiters[i] != current_iter){
			csums[ind] <- accumulator
			ind <- ind + 1
			accumulator <- 0
			current_iter <- cfirmiters[i]	
		}
		accumulator <- accumulator + cfirmvector[i]
	}
	csums[ind] <- accumulator
	
	for (i in 1:niter){
		gdp[i] <- fsums[i] + csums[i]
	}
	fname = paste("GDP_", gtype, "_Monthly.png", sep = "")
	ylabtext = paste("GDP (Total Production Market Value - ", gtype, sep = "")
	title = expression(beta ~ "=" ~ 0.3)
	png(fname, width = 1500, height = 800, pointsize=18)
	plot(gdp~times, type="l", col = "blue", lwd = 3, xlab = "Months", ylab=ylabtext, main = title)
	#lines(fsums~times, type = "o")
	dev.off()
	
	nquarters = niter / 3
	quarters <- (1:nquarters)
	gdpquarters <- (1:nquarters)
	accumulator <- 0
	ind <- 1
	for (i in 1:niter){
		if (i %% 3 == 0){
			accumulator <- accumulator + gdp[i]
			gdpquarters[ind] <- accumulator
			ind <- ind + 1
			accumulator <- 0
			}
		else{
			accumulator <- accumulator + gdp[i]
			}
	}
	fname = paste("GDP_", gtype, "_Quarterly.png", sep = "")
	png(fname, width = 1500, height = 800, pointsize=18)
	plot(gdpquarters~quarters, type="l", col = "blue", lwd = 3, xlab = "Quarters", ylab=ylabtext, main = title)
	dev.off()
	
	nyears = niter / 12
	years <- (1:nyears)
	gdpyears <- (1:nyears)
	accumulator <- 0
	ind <- 1
	for (i in 1:niter){
		if (i %% 12 == 0){
			accumulator <- accumulator + gdp[i]
			gdpyears[ind] <- accumulator
			ind <- ind + 1
			accumulator <- 0
			}
		else{
			accumulator <- accumulator + gdp[i]
			}
	}
	
	fname = paste("GDP_", gtype, "_Yearly.png", sep = "")
	png(fname, width = 1500, height = 800, pointsize=18)
	plot(gdpyears~years, type="l", col = "blue", lwd = 3, xlab = "Years", ylab=ylabtext, main = title)
	dev.off()
	return(gdpyears)
}

plot_gdp_to_file_v2 <- function(niter, firmiters, firmvector, cfirmiters, cfirmvector, Rfirmvector, Rcfirmvector){
	times <- (1:niter)
	fsums <- (1:niter)
	csums <- (1:niter)
	gdp <- (1:niter)
	
	Rfsums <- (1:niter)
	Rcsums <- (1:niter)
	Rgdp <- (1:niter)
	
	
	#Regular Firm productions
	current_iter <- firmiters[1]
	datalength <- length(firmvector)
	accumulator <- 0
	Raccumulator <- 0
	ind <- 1
	for (i in 1:datalength){
		if (firmiters[i] != current_iter){
			fsums[ind] <- accumulator
			Rfsums[ind] <- Raccumulator
			ind <- ind + 1
			accumulator <- 0
			Raccumulator <- 0
			current_iter <- firmiters[i]	
		}
		accumulator <- accumulator + firmvector[i]
		Raccumulator <- Raccumulator + Rfirmvector[i]
	}
	fsums[ind] <- accumulator
	Rfsums[ind] <- Raccumulator

    #constructor Firm productions
	current_iter <- cfirmiters[1]
	datalength <- length(cfirmvector)
	accumulator <- 0
	Raccumulator <- 0
	ind <- 1
	for (i in 1:datalength){
		if (cfirmiters[i] != current_iter){
			csums[ind] <- accumulator
			Rcsums[ind] <- Raccumulator
			ind <- ind + 1
			accumulator <- 0
			Raccumulator <- 0
			current_iter <- cfirmiters[i]	
		}
		accumulator <- accumulator + cfirmvector[i]
		Raccumulator <- Raccumulator + Rcfirmvector[i]
	}
	csums[ind] <- accumulator
	Rcsums[ind] <- Raccumulator
	
	for (i in 1:niter){
		gdp[i] <- fsums[i] + csums[i]
		Rgdp[i] <- Rfsums[i] + Rcsums[i]
	}
	fname = "GDP_Monthly.png"
	ylabtext = "GDP - Growth of Housing Units and Consumption Goods Production"
	title = expression(beta ~ "=" ~ 0.3)

	png(fname, width = 1500, height = 800, pointsize=18)
	valrange <- gdp
	valrange[1] <- min(Rgdp)
	plot(valrange~times, type="n", xlab = "Months", ylab=ylabtext, main = title)
	lines(gdp~times, type="l", col = "red", lwd = 3)
	lines(Rgdp~times, type = "l", col = "blue", lwd = 3)
	legend("topleft", c("Nominal","Real"), lty = c(1,1), lwd = c(2,2), col = c("red", "blue"))
	dev.off()
	
	nquarters = niter / 3
	quarters <- (1:nquarters)
	gdpquarters <- (1:nquarters)
	Rgdpquarters <- (1:nquarters)
	accumulator <- 0
	Raccumulator <- 0
	ind <- 1
	for (i in 1:niter){
		if (i %% 3 == 0){
			accumulator <- accumulator + gdp[i]
			Raccumulator <- Raccumulator + Rgdp[i]
			gdpquarters[ind] <- accumulator
			Rgdpquarters[ind] <- Raccumulator
			ind <- ind + 1
			accumulator <- 0
			Raccumulator <- 0
			}
		else{
			accumulator <- accumulator + gdp[i]
			Raccumulator <- Raccumulator + Rgdp[i]
			}
	}
	fname = "GDP_Quarterly.png"
	png(fname, width = 1500, height = 800, pointsize=18)
	valrange <- gdpquarters
	valrange[1] <- min(Rgdpquarters)
	plot(valrange~quarters, type="n", xlab = "Quarters", ylab=ylabtext, main = title)
	lines(gdpquarters~quarters, type="l", col = "red", lwd = 3)
	lines(Rgdpquarters~quarters, type = "l", col = "blue", lwd = 3)
	legend("topleft", c("Nominal","Real"), lty = c(1,1), lwd = c(2,2), col = c("red", "blue"))
	dev.off()
	
	nyears = niter / 12
	years <- (1:nyears)
	gdpyears <- (1:nyears)
	accumulator <- 0
	Rgdpyears <- (1:nyears)
	Raccumulator <- 0
	ind <- 1
	for (i in 1:niter){
		if (i %% 12 == 0){
			accumulator <- accumulator + gdp[i]
			gdpyears[ind] <- accumulator
			Raccumulator <- Raccumulator + Rgdp[i]
			Rgdpyears[ind] <- Raccumulator
			ind <- ind + 1
			accumulator <- 0
			Raccumulator <- 0
			}
		else{
			accumulator <- accumulator + gdp[i]
			Raccumulator <- Raccumulator + Rgdp[i]
			}
	}
	
	fname = "GDP_Yearly.png"
	png(fname, width = 1500, height = 800, pointsize=18)
	valrange <- gdpyears
	valrange[1] <- min(Rgdpyears)
	plot(valrange~years, type="n", xlab = "Years", ylab=ylabtext, main = title)
	lines(gdpyears~years, type="l", col = "red", lwd = 3)
	lines(Rgdpyears~years, type = "l", col = "blue", lwd = 3)
	legend("topleft", c("Nominal","Real"), lty = c(1,1), lwd = c(2,2), col = c("red", "blue"))
	dev.off()
	return(gdpyears)
}
plot_time_series_banks <- function(niter, idvector, bank_1, bank_2, memoryvector, xlabel, ylabel, title, fname){
        times <- (1:niter)
        bankA <- (1:niter)
        bankB <- (1:niter)
        indA <- 1;
        indB <- 1;
        bmin <- min(memoryvector)
        bmax <- max(memoryvector)
        valrange <- (1:niter)
        valrange[1] <- bmin
        valrange[-1] <- bmax
        datalength <- length(memoryvector)
        for (i in 1:datalength){
                if (idvector[i] == bank_1){
                        bankA[indA] <- memoryvector[i]
                        indA <- indA + 1        
                }
                else{
                        bankB[indB] <- memoryvector[i]
                        indB <- indB + 1
                        }
        }
        legA = paste("Bank ID = ", as.character(bank_1),  sep ='')
        legB = paste("Bank ID = ", as.character(bank_2),  sep ='')
        png(fname, width = 1500, height = 800, pointsize=16)
        plot(valrange~times, type="n", xlab = xlabel, ylab=ylabel, main = title)
        lines(bankA~times, type="l", col="red", lwd=3)
        lines(bankB~times, type="l", col="blue", lwd=3)
        legend("topleft", c(legA,legB), lty = c(1,1), lwd = c(3,3), col = c("red", "blue"))
        dev.off()
}
	

########## Single Run Anals #####

data_dir = "/Users/bulent/Documents/AWorkspace/iceace/FLAME/outputs/data"
output_dir = "/Users/bulent/Documents/AWorkspace/iceace/FLAME/outputs/plots/"
setwd(output_dir)


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
nFirms = 12
nCFirms = 3
nBanks = length(BankIncome$ID) / nQuarters
nIter <- nQuarters


#MALL:
plot_time_series_point_file(nWeeks, Mall$AVG_GOODS_PRICE, "Weeks", "Average Unit Goods Price", "Consumption Goods Market", "MallAvgGoodsPrice.png")
plot_time_series_point_file(nWeeks, Mall$TRANSACTION_QUANTITY, "Weeks", "Number of Transactions", "Consumption Goods Market", "MallTransactionVolumeGoods.png")

#Real Estate Agency
plot_time_series_point_file(nMonths, REAgency$AVG_HOUSING_PRICE, "Months", "Average Unit Housing Price", "Real Estate Market", "REAgencyAvgHousingPrice.png")
plot_time_series_point_file(nMonths, REAgency$TRANSACTION_QUANTITY, "Months", "Number of Housing Transactions", "Real Estate Market", "REAgencyTransactionVolumeHouses.png")

#Central Bank
plot_time_series_point_file(nQuarters, Centralbank$INTEREST_RATE, "Quarters", "Interest Rate", "Central Bank", "CentralBankInterestRate.png")
plot_time_series_point_file(nQuarters, Centralbank$INFLATION, "Quarters", "Inflation", "Central Bank", "CentralBankInflation.png")

#Government
plot_time_series_point_file(nQuarters, Government$UNEMPLOYMENT_RATE, "Quarters", "Unemployment Rate", "", "GovernmentUnemploymentRate.png")
plot_time_series_point_file(nQuarters, Government$LABOUR_TAX_RATE, "Quarters", "Tax Rate (labour/Capital)", "Government", "GovernmentTaxRate.png")
plot_time_series_point_file(nQuarters, Government$GOV_GENERAL_BENEFIT_RATE, "Quarters", "General Benefits Rate", "Government", "GovernmentBenefitsRate.png")
plot_time_series_point_file(nQuarters, Government$UNEMPLOYMENT_BENEFITS, "Quarters", "Unemployment Benefits", "", "GovernmentBenefitsUnemployment.png")
plot_time_series_point_file(nQuarters, Government$GENERAL_BENEFITS, "Quarters", "General Benefits", "Government", "GovernmentBenefitsGeneral.png")
plot_time_series_point_file(nQuarters, Government$AVERAGE_WAGE, "Quarters", "Average Wage", "", "GovernmentAverageWage.png")

#Equity Fund
plot_time_series_point_file(nQuarters, Equityfund$DIVIDENDS_RECIEVED, "Quarters", "Dividends Received", "Equity Fund", "FundDividendsReceived.png")
plot_time_series_point_file(nQuarters, Equityfund$DIVIDENDS_RETAINED, "Quarters", "Dividends Retained", "Equity Fund", "FundDividendsRetained.png")
plot_time_series_point_file(nQuarters, Equityfund$LIQUIDITY, "Quarters", "Liquidity ", "Equity Fund", "FundLiquidity.png")
plot_time_series_multiline_point_file(nQuarters, Equityfund$SHARE_FIRMS, Equityfund$SHARE_CONSTRUCTION_FIRMS, Equityfund$SHARE_BANKS, "Quarters", "Shares Recieved", "Equity Fund", "FundShares.png", c("Firms", "CFirms", "Banks"))

#Banks
plot_time_series_banks(nQuarters, BankBalance$ID, 21, 22, BankBalance$LOANS, "Quarters", "Loans to Firms", "Banks", "BanksLoans.png")
plot_time_series_banks(nQuarters, BankBalance$ID, 21, 22, BankBalance$MORTGAGES, "Quarters", "Mortgages to Households", "Banks", "BanksMortgages.png")
plot_time_series_banks(nQuarters, BankBalance$ID, 21, 22, BankBalance$DEPOSITS, "Quarters", "Deposits from Firms and Households", "Banks", "BanksDeposits.png")
plot_time_series_banks(nQuarters, BankBalance$ID, 21, 22, BankBalance$CENTRALBANK_DEBT, "Quarters", "Central Bank Debt", "Banks", "BanksDebt.png")
plot_time_series_banks(nQuarters, BankBalance$ID, 21, 22, BankBalance$EQUITY, "Quarters", "Equity", "Banks", "BanksEquity.png")
plot_time_series_banks(nQuarters, BankIncome$ID, 21, 22, BankIncome$INTERESTS_ACCRUED, "Quarters", "Interests Collected on Mortgages and Loans", "Banks", "BanksInterestsCollected.png")
plot_time_series_banks(nQuarters, BankIncome$ID, 21, 22, BankIncome$TOTAL_WRITEOFFS, "Quarters", "Total Loan and Mortgage Writeoffs", "Banks", "BanksWriteoffs.png")
plot_time_series_banks(nQuarters, BankIncome$ID, 21, 22, BankIncome$INTERESTS_PAID, "Quarters", "Interests Paid to Central Bank", "Banks", "BanksInterestsPaid.png")
plot_time_series_banks(nQuarters, BankIncome$ID, 21, 22, BankIncome$NET_EARNINGS, "Quarters", "Net Earnings", "Banks", "BanksNetEarnings.png")
plot_time_series_banks(nQuarters, BankIncome$ID, 21, 22, BankIncome$TOTAL_DIVIDENDS, "Quarters", "Dividends Sent to Fund", "Banks", "BanksTotalDividends.png")


#plot_time_series_mean_file(nBanks, nQuarters, BankBalance$LOANS, "Quarters", "Loans to Firms (Mean)", "Banks", "Loans.png")
#plot_time_series_mean_file(nBanks, nQuarters, BankBalance$MORTGAGES, "Quarters", "Mortgages to Households (Mean)", "Banks", "Mortgages.png")
#plot_time_series_mean_file(nBanks, nQuarters, BankBalance$DEPOSITS, "Quarters", "Deposits from Firms, HH (Mean)", "Banks", "Deposits.png")
#plot_time_series_mean_file(nBanks, nQuarters, BankBalance$CENTRALBANK_DEBT, "Quarters", "Central Bank Debt (Mean)", "Banks", "BanksDebt.png")
#plot_time_series_mean_file(nBanks, nQuarters, BankBalance$EQUITY, "Quarters", "Equity (Mean)", "Banks", "BanksEquity.png")
#plot_time_series_mean_file(nBanks, nQuarters, BankIncome$INTERESTS_ACCRUED, "Months", "Interests Collected Mortgage + Loans (Mean)", "Banks", "BanksInterestsCollected.png")
#plot_time_series_mean_file(nBanks, nQuarters, BankIncome$TOTAL_WRITEOFFS, "Quarters", "Total Loans + Mortgages Writeoffs (Mean)", "Banks", "BanksWriteoffs.png")
#plot_time_series_mean_file(nBanks, nQuarters, BankIncome$INTERESTS_PAID, "Months", "Interests Paid (Mean)", "Banks", "BanksInterestsPaid.png")
#plot_time_series_mean_file(nBanks, nQuarters, BankIncome$NET_EARNINGS, "Months", "Net Earnings (Mean)", "Banks", "BanksNetEarnings.png")


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

#### Validation - Begin ##########

##### Compute GDP #######
cfirmvector <- CFirmMonthly$PRODUCTION_CURRENT * CFirmMonthly$UNIT_HOUSE_PRICE
firmvector <- FirmMonthly$PRODUCTION_CURRENT * FirmMonthly$AVERAGE_GOODS_PRICE
plot_gdp_to_file_v1(nMonths, FirmMonthly$IT_NO,firmvector, CFirmMonthly$IT_NO, cfirmvector)

cfirmvector_real <- CFirmMonthly$PRODUCTION_CURRENT * CFirmMonthly$UNIT_HOUSE_PRICE[1]
firmvector_real <- FirmMonthly$PRODUCTION_CURRENT * FirmMonthly$AVERAGE_GOODS_PRICE[1]
plot_gdp_to_file_v1(nMonths, FirmMonthly$IT_NO,firmvector_real, CFirmMonthly$IT_NO, cfirmvector_real, gtype = "Real")

plot_gdp_to_file_v2(nMonths, FirmMonthly$IT_NO,firmvector, CFirmMonthly$IT_NO, cfirmvector, firmvector_real, cfirmvector_real)


##### Compute Bankruptcy #######
file = paste(data_dir, '/', "BankruptcyInspection.txt", sep ='')
Bankruptcy <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
L <- Bankruptcy$Writeoff_Type == "Insolvency"
Insolvencies <-Bankruptcy[L,]
L <- Bankruptcy$Writeoff_Type == "Illiquidity"
Illiquidities <-Bankruptcy[L,]
L <- Bankruptcy$Writeoff_Type == "Mortgages"
Mortgages <-Bankruptcy[L,]

get_single_occurances <- function(dataf){
	npoints <- length(dataf[["IT"]])
	L <- (1:npoints)
	L <- L >= 1
	id_pre <- 0
	it_pre <- 0
	for (i in 1:npoints){
		id <- dataf[["IT"]][i]
		it <- dataf[["ID"]][i]
		if (id == id_pre & it == it_pre){
			L[i] <- FALSE
			}
		id_pre <- id
		it_pre <- it
	}
	return(dataf[L,])
}

get_occurances_distro <- function(niter, itvector){
	nquarters <- niter %/% 60
	quarters <- rep(0, nquarters)
	datalen <- length(itvector)
	acc <- 0
	ind <- 1
	for (i in 1:datalen){
		ind <- itvector[i] %/% 60 + 1
		quarters[ind] = quarters[ind] + 1
	}
	return(quarters)
}

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

plot_time_series_multiline_point_file(nQuarters, freqmort, freqinsolv, freqilliquid, "Quarters", "Frequency", "Defaults", "Defaults.png", c("Mortgages", "Insolvencies", "Illiquidities"))

####### Validation - End #########

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


###### Initialization Check ######
Firm_file = paste(data_dir, '/VV/', "Firm_ID_Liquidity_Loan.txt", sep ='')
HH_file = paste(data_dir, '/VV/', "Household_ID_Liquidity_Mortgages.txt", sep ='')
HH_init <- read.csv(HH_file, sep = " ", header = F, stringsAsFactors = F)
Firm_init <- read.csv(Firm_file, sep = " ", header = F, stringsAsFactors = F)

household_deposits <- sum(HH_init[[2]])
firm_deposits <- sum(Firm_init[[2]])
bank_deposits <- firm_deposits + household_deposits

household_mortgages <- sum(HH_init[[3]])
firm_loans <- sum(Firm_init[[3]])
bank_risky <- household_mortgages + firm_loans

