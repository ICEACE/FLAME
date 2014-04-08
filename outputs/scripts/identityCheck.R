
file = paste(data_dir, '/', "ICEACE_identity_bank.txt", sep ='')
banksData <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)

# Time Invariant I:
loans <- get_aggregate_values(banksData$IT_NO, banksData$LOANS)
mortgages <- get_aggregate_values(banksData$IT_NO, banksData$MORTGAGES)
depositsPrivate <- get_aggregate_values(banksData$IT_NO, banksData$DEPOSITS)
equity <- get_aggregate_values(banksData$IT_NO, banksData$EQUITY)
ICB <- get_aggregate_values(banksData$IT_NO, banksData$INTERESTS_PAID)
depositsPublic <- Centralbank$LIQUIDITY_GOVERNMENT
depositBanks <- Centralbank$LIQUIDITY_BANKS
credit_money <- loans + mortgages
right_sideOne <- depositsPrivate + equity + depositsPublic
differenceOne <- credit_money - right_sideOne

# Time Invariant II: 
moneysources <- Centralbank$LOANS_BANK + Centralbank$LOANS_GOVERNMENT
moneylocations <- Centralbank$LIQUIDITY_BANKS + Centralbank$LIQUIDITY_GOVERNMENT + Centralbank$LIQUIDITY_EQUITYFUND 
differenceTwo <- moneysources - moneylocations


plot_time_series_multiline_point_file(length(loans), loans, mortgages, "Quarters", "Total", "ICEACE Identity - Credit Money", "IceaceIdentity_LeftSide.png", c("Loans", "Mortgages"), isgrid = F, ispoint = F)

plot_time_series_multiline_point_file(length(depositsPrivate), depositsPrivate, depositsPublic, "Quarters", "Amount", "Deposits, Banks' Equity and Interests paid by Banks to CB", "IceaceIdentity_RightSide.png", c("Deposits Private Sector", "Deposits Government", "Banks' Equity", "Interests Paid Quarterly"), v3 = equity, v4 = ICB, isgrid = F, ispoint = F)


plot_time_series_multiline_point_file(length(depositsPrivate), depositsPrivate, depositsPublic, "Quarters", "Amount", "Deposits, Banks' Equity and Interests paid by Banks to CB", "IceaceIdentity_RightSideCum.png", c("Deposits Private Sector", "Deposits Government", "Banks' Equity", "Cumulative Interests"), v3 = equity, v4 = cumsum(ICB), isgrid = F, ispoint = F)

plot_time_series_multiline_point_file(length(credit_money), credit_money, right_sideOne, "Quarters", "Total", "ICEACE Identity - I", "IceaceIdentityOne.png", c("Loans + Mortgages", "Private Deposits + Gov. Liquidity + Banks' Equity", "The difference"), v3 = differenceOne, isgrid = F, ispoint = F)

plot_time_series_multiline_point_file(length(loans), moneysources, moneylocations, "Quarters", "Total", "ICEACE Identity - II", "IceaceIdentityTwo.png", c("Central Bank Loans to Banks and Gov.", "Deposits at the Central Bank", "The difference"), v3 = differenceTwo, isgrid = F, ispoint = F)

