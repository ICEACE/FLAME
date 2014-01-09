## Compute Crediting Frequencies ##

file = paste(data_dir, '/', "Firm_Quarterly_BalanceSheet.txt", sep ='')
FirmBalance <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
file = paste(data_dir, '/', "Constructor_Firm_Quarterly_BalanceSheet.txt", sep ='')
CFirmBalance <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)

# Regular Firms #
Fneed <- get_aggregate_values(FirmBalance$IT_NO, FirmBalance$ISLIQUIDSHORT)
Floan <- get_aggregate_values(FirmBalance$IT_NO, FirmBalance$HASLOAN)
Finvest <- get_aggregate_values(FirmBalance$IT_NO, FirmBalance$HASINVESTMENT)
plot_time_series_multiline_point_file(nQuarters, Fneed, Floan, "Quarters", "Frequencies", "Regular Firm Liquidity Needs vs Bank Loans and Fund Investments", "aCredittingFirm.png", c("Liquidity Shortage", "Loans", "Investment"), v3 = Finvest, legposn = "topright", ptype = "o")

#Constructor Firms #
cFneed <- get_aggregate_values(CFirmBalance$IT_NO, CFirmBalance$ISLIQUIDSHORT)
cFloan <- get_aggregate_values(CFirmBalance$IT_NO, CFirmBalance$HASLOAN)
cFinvest <- get_aggregate_values(CFirmBalance$IT_NO, CFirmBalance$HASINVESTMENT)
plot_time_series_multiline_point_file(nQuarters, cFneed, cFloan, "Quarters", "Frequencies", "Constructor Firm Liquidity Needs vs Bank Loans and Fund Investments", "aCredittingCFirm.png", c("Liquidity Shortage", "Loans", "Investment"), v3 = cFinvest, legposn = "topright", ptype = "o")
