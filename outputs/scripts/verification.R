
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
