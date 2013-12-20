# Compute Bankruptcy Frequencies #
file = paste(data_dir, '/', "BankruptcyInspection.txt", sep ='')
Bankruptcy <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
L <- Bankruptcy$Writeoff_Type == "Insolvency"
Insolvencies <-Bankruptcy[L,]
L <- Bankruptcy$Writeoff_Type == "Illiquidity"
Illiquidities <-Bankruptcy[L,]
L <- Bankruptcy$Writeoff_Type == "Mortgage"
Mortgages <-Bankruptcy[L,]

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

plot_time_series_multiline_point_file(nQuarters, freqmort, freqinsolv, v3 = freqilliquid, "Quarters", "Frequency", "Defaults", "aWriteoffTypesAndFrequencies.png", c("Mortgages", "Insolvencies", "Illiquidities"), isgrid = T, ptype = "o")

plot_time_series_point_file(nQuarters, freqmort, "Quarters", "Frequency", "Mortgage Writeoffs", "aWriteoffMortgages.png", isgrid = T, ltype = "h", ispoint = T)

plot_time_series_point_file(nQuarters, freqilliquid, "Quarters", "Frequency", "Illiquidity Writeoffs", "aWriteoffIlliquidity.png", isgrid = T, ltype = "h", ispoint = T)

plot_time_series_point_file(nQuarters, freqinsolv, "Quarters", "Frequency", "Insolvency Writeoffs", "aWriteoffInsolvency.png", isgrid = T, ltype = "h", ispoint = T)
