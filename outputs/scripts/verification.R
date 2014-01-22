
###### Initialization Check ######
Firm_file = paste(data_dir, "Firm_ID_Liquidity_Loan.txt", sep ='')
HH_file = paste(data_dir, "Household_ID_Liquidity_Mortgages.txt", sep ='')
HH_init <- read.csv(HH_file, sep = " ", header = F, stringsAsFactors = F)
Firm_init <- read.csv(Firm_file, sep = " ", header = F, stringsAsFactors = F)

## Initial Deposits #
household_deposits <- sum(HH_init[[2]])
firm_deposits <- sum(Firm_init[[2]])
bank_deposits <- firm_deposits + household_deposits
sum(BankBalance$DEPOSITS[1:2])
bank_deposits

### Initial Mortgages ##
HHMortgagesInit <- sum(HH_init[[3]])
BankMortgagesInit <- sum(BankBalance$MORTGAGES[1:2])
HHMortgagesInit - BankMortgagesInit

### Initial Loans ##
FirmLoansInit <- sum(Firm_init[[3]])
BankLoansInit <- sum(BankBalance$LOANS[1:2])
BankLoansInit
FirmLoansInit



###### Flow of Housing Units :: New sales VS Total owned ####
HHLast <- sum(tail(HouseholdMonthlyFirst$HOUSING_UNITS, 800))
HHFirst <- sum(head(HouseholdMonthlyFirst$HOUSING_UNITS, 800))
new <- sum(CFirmMonthly$SALES) - sum(CFirmMonthly$SALES[1:3])
HHLast
HHFirst
new
HHLast - HHFirst

###### Flow of Consumption Goods :: Sales VS Buys ####
HHLast <- tail(HouseholdWeekly, 800 * 8)
head(HHLast)
tail(HHLast)
FirmLast <- tail(FirmMonthly,12)
FirmLast
HHPreLast <- sum(head(HHLast$quantity_bought, 800 * 4))
FirmLast <- sum(tail(FirmLast$SALES,12))
FirmLast
HHPreLast

#### Mortgages ####
HHMortgagesFirst <- sum(head(HouseholdQuarterly$MORTGAGES, 800))
BankMortgagesFirst <- sum(head(BankBalance$MORTGAGES,2))
HHMortgagesFirst - HHMortgagesInit
BankMortgagesFirst - HHMortgagesInit

HHMortgagesSecond <- sum(HouseholdQuarterly[801:1600,]$MORTGAGES)
BankMortgagesSecond <- sum(BankBalance[3:4,]$MORTGAGES)
BankMortgagesSecond - HHMortgagesSecond


head(tail(HouseholdQuarterly$MORTGAGES, 800))
tail(BankBalance$MORTGAGES,2)
sum(tail(BankBalance$MORTGAGES,2)) - sum(tail(HouseholdQuarterly$MORTGAGES, 800))


#### Loans :: Firms VS Banks ###

BankLoansFirst <- sum(BankBalance[1:2,]$LOANS)
BankLoansSecond <- sum(BankBalance[3:4,]$LOANS)
BankLoansLast <- sum(tail(BankBalance, 2)$LOANS)

CFirmLoanLastPre <- sum(head(tail(CFirmBalance, 6),3)$DEBT)
FirmLoanLastPre <- sum(head(tail(FirmBalance, 24),12)$DEBT)
FirmLoanLastPre + CFirmLoanLastPre

#### Debts :: Central Bank VS Banks and Governments ###
head(tail(Centralbank$LOANS_GOVERNMENT,2),1) - tail(Government$DEBT,1)
sum(tail(BankBalance$CENTRALBANK_DEBT, 2)) - tail(Centralbank$LOANS_BANKS,1)

# Taylors Rule:
indexed_prices <- (((Mall$AVG_GOODS_PRICE - Mall$AVG_GOODS_PRICE[1])/Mall$AVG_GOODS_PRICE) + 1)

infl_target <-  0.02
infl <- Centralbank$INFL
u <- Government$UNEMPLOYMENT_RATE
rcb <- infl + (infl - infl_target) * 0.5 - u * 0.5

CB <- Centralbank[1:3]
CB$taylor <- rcb

# ICEACE Invariant -
### Init Workspace  ###
rm(list = ls())
source("/Users/bulent/Documents/AWorkspace/iceace/FLAME/outputs/scripts/LibIceace.R", echo = TRUE)
data_dir = "/Users/bulent/Documents/AWorkspace/iceace/FLAME/outputs/data"
output_dir = "/Users/bulent/Documents/AWorkspace/iceace/FLAME/outputs/plots/"
setwd(output_dir)

file = paste(data_dir, '/', "ICEACE_identity_bank.txt", sep ='')
banksData <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)

file = paste(data_dir, '/', "ICEACE_identity_cb.txt", sep ='')
govMoney <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)

loans <- get_aggregate_values(banksData$IT_NO, banksData$LOANS)
mortgages <- get_aggregate_values(banksData$IT_NO, banksData$MORTGAGES)
depositsPrivate <- get_aggregate_values(banksData$IT_NO, banksData$DEPOSITS)
equity <- get_aggregate_values(banksData$IT_NO, banksData$EQUITY)
ICB <- get_aggregate_values(banksData$IT_NO, banksData$INTERESTS_PAID)
depositsPublic <- govMoney$LIQ

credit_money <- loans + mortgages

right_side0 <- depositsPrivate + equity + depositsPublic
right_side <- depositsPrivate + equity + depositsPublic - ICB
right_side_cum <- depositsPrivate + equity + depositsPublic - cumsum(ICB)

difference0 <- credit_money - right_side0
difference <- credit_money - right_side
difference_cum <- credit_money - right_side_cum

plot_time_series_multiline_point_file(length(loans), loans, mortgages, "Quarters", "Total", "ICEACE Identity - Credit Money", "IceaceIdentity_LeftSide.png", c("Loans", "Mortgages"), isgrid = F, ispoint = F)

plot_time_series_multiline_point_file(length(depositsPrivate), depositsPrivate, depositsPublic, "Quarters", "Amount", "Deposits, Banks' Equity and Interests paid by Banks to CB", "IceaceIdentity_RightSide.png", c("Deposits Private Sector", "Deposits Government", "Banks' Equity", "Interests Paid Quarterly"), v3 = equity, v4 = ICB, isgrid = F, ispoint = F)


plot_time_series_multiline_point_file(length(depositsPrivate), depositsPrivate, depositsPublic, "Quarters", "Amount", "Deposits, Banks' Equity and Interests paid by Banks to CB", "IceaceIdentity_RightSideCum.png", c("Deposits Private Sector", "Deposits Government", "Banks' Equity", "Cumulative Interests"), v3 = equity, v4 = cumsum(ICB), isgrid = F, ispoint = F)

plot_time_series_multiline_point_file(length(credit_money), credit_money, right_side0, "Quarters", "Total", "ICEACE Identity", "IceaceIdentityNoICB.png", c("Loans + Mortgages", "Private Deposits + Gov. Deposits + Banks' Equity", "The difference"), v3 = difference0, isgrid = F, ispoint = F)

#plot_time_series_multiline_point_file(length(credit_money), credit_money,right_side_cum, "Quarters", "Total", "ICEACE Identity", "IceaceIdentityCum.png", c("Loans + Mortgages", "Private Deposits + Gov. Deposits + Banks' Equity - Interests Paid Cumulative to Central Bank", "The difference"), v3 = difference_cum, isgrid = F, ispoint = F)

#plot_time_series_multiline_point_file(length(credit_money), credit_money, right_side, "Quarters", "Total", "ICEACE Identity", "IceaceIdentity.png", c("Loans + Mortgages", "Private Deposits + Gov. Deposits + Banks' Equity - Quarterly Interests Paid to Central Bank", "The difference"), v3 = difference, isgrid = F, ispoint = F)





########
file = paste(data_dir, '/0.20/', "Government_snapshot.txt", sep ='')
Government0.20 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
file = paste(data_dir, '/0.25/', "Government_snapshot.txt", sep ='')
Government0.25 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
file = paste(data_dir, '/0.30/', "Government_snapshot.txt", sep ='')
Government0.30 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
file = paste(data_dir, '/0.40/', "Government_snapshot.txt", sep ='')
Government0.40 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)

file = paste(data_dir, '/0.20/', "CentralBank_snapshot.txt", sep ='')
Centralbank0.20 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
file = paste(data_dir, '/0.25/', "CentralBank_snapshot.txt", sep ='')
Centralbank0.25 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
file = paste(data_dir, '/0.30/', "CentralBank_snapshot.txt", sep ='')
Centralbank0.30 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
file = paste(data_dir, '/0.40/', "CentralBank_snapshot.txt", sep ='')
Centralbank0.40 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)

file = paste(data_dir, '/0.20/', "Bank_BalanceSheet.txt", sep ='')
BankBalance0.20 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
file = paste(data_dir, '/0.25/', "Bank_BalanceSheet.txt", sep ='')
BankBalance0.25 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
file = paste(data_dir, '/0.30/', "Bank_BalanceSheet.txt", sep ='')
BankBalance0.30 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)
file = paste(data_dir, '/0.40/', "Bank_BalanceSheet.txt", sep ='')
BankBalance0.40 <- read.csv(file, sep = " ", header = T, stringsAsFactors = F)


## Private Sector Debts:

# Loans>
loans0.20 <- get_aggregate_values(BankBalance0.20$IT_NO, BankBalance0.20$LOANS)
loans0.25 <- get_aggregate_values(BankBalance0.25$IT_NO, BankBalance0.25$LOANS)
loans0.30 <- get_aggregate_values(BankBalance0.30$IT_NO, BankBalance0.30$LOANS)
loans0.40 <- get_aggregate_values(BankBalance0.40$IT_NO, BankBalance0.40$LOANS)

# Mortgages>
mortgages0.20 <- get_aggregate_values(BankBalance0.20$IT_NO, BankBalance0.20$MORTGAGES)
mortgages0.25 <- get_aggregate_values(BankBalance0.25$IT_NO, BankBalance0.25$MORTGAGES)
mortgages0.30 <- get_aggregate_values(BankBalance0.30$IT_NO, BankBalance0.30$MORTGAGES)
mortgages0.40 <- get_aggregate_values(BankBalance0.40$IT_NO, BankBalance0.40$MORTGAGES)

# Private Sector Debt>
privatedebt0.20 <- mortgages0.20 + loans0.20
privatedebt0.25 <- mortgages0.25 + loans0.25
privatedebt0.30 <- mortgages0.30 + loans0.30
privatedebt0.40 <- mortgages0.40 + loans0.40


# Private Sector Deposits>
privatedeposits0.20 <- get_aggregate_values(BankBalance0.20$IT_NO, BankBalance0.20$DEPOSITS)
privatedeposits0.25 <- get_aggregate_values(BankBalance0.25$IT_NO, BankBalance0.25$DEPOSITS)
privatedeposits0.30 <- get_aggregate_values(BankBalance0.30$IT_NO, BankBalance0.30$DEPOSITS)
privatedeposits0.40 <- get_aggregate_values(BankBalance0.40$IT_NO, BankBalance0.40$DEPOSITS)

# Banks' Equity>
banksequity0.20 <- get_aggregate_values(BankBalance0.20$IT_NO, BankBalance0.20$EQUITY)
banksequity0.25 <- get_aggregate_values(BankBalance0.25$IT_NO, BankBalance0.25$EQUITY)
banksequity0.30 <- get_aggregate_values(BankBalance0.30$IT_NO, BankBalance0.30$EQUITY)
banksequity0.40 <- get_aggregate_values(BankBalance0.40$IT_NO, BankBalance0.40$EQUITY)

