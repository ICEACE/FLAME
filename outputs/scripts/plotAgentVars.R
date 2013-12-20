#MALL:
plot_time_series_point_file(nWeeks, Mall$AVG_GOODS_PRICE, "Weeks", "Average Unit Goods Price", "Consumption Goods Market", "MallAvgGoodsPrice.png")
plot_time_series_point_file(nWeeks, Mall$TRANSACTION_QUANTITY, "Weeks", "Number of Transactions", "Consumption Goods Market", "MallTransactionVolumeGoods.png")

#Real Estate Agency
plot_time_series_point_file(nMonths, REAgency$AVG_HOUSING_PRICE, "Months", "Average Unit Housing Price", "Real Estate Market", "REAgencyAvgHousingPrice.png")
plot_time_series_point_file(nMonths, REAgency$TRANSACTION_QUANTITY, "Months", "Number of Housing Transactions", "Real Estate Market", "REAgencyTransactionVolumeHouses.png")

#Central Bank
plot_time_series_point_file(nQuarters, Centralbank$INTEREST_RATE, "Quarters", "Interest Rate", "Central Bank", "CentralBankInterestRate.png", isgrid = TRUE, ltype = "o")
plot_time_series_point_file(nQuarters, Centralbank$INFLATION, "Quarters", "Inflation", "Central Bank", "CentralBankInflation.png", isgrid = TRUE, ltype = "o")
plot_time_series_point_file(nQuarters, Centralbank$REVENUES, "Quarters", "Interests Accrued", "Central Bank", "CentralBankRevenues.png", isgrid = TRUE, ltype = "o")
plot_time_series_point_file(nQuarters, Centralbank$FIAT_MONEY, "Quarters", "FIAT Money", "Central Bank", "CentralBankFiatMoney.png", isgrid = TRUE, ltype = "o")
plot_time_series_point_file(nQuarters, Centralbank$TOTAL_ASSETS, "Quarters", "Total Assets", "Central Bank", "CentralBankTotalAssets.png", isgrid = TRUE, ltype = "o")
plot_time_series_point_file(nQuarters, Centralbank$LIQUIDITY, "Quarters", "Liquidity", "Central Bank", "CentralBankLiquidity.png", isgrid = TRUE, ltype = "o")
plot_time_series_point_file(nQuarters, Centralbank$LOANS_BANKS, "Quarters", "Bank Loans", "Central Bank", "CentralBankLoansBanks.png", isgrid = TRUE, ltype = "o")
plot_time_series_point_file(nQuarters, Centralbank$LOANS_GOVERNMENT, "Quarters", "Governement Loan", "Central Bank", "CentralBankLoansGovernment.png", isgrid = TRUE, ltype = "o")
plot_time_series_point_file(nQuarters, Centralbank$EQUITY, "Quarters", "Equity", "Central Bank", "CentralBankEquity.png", isgrid = TRUE, ltype = "o")
plot_time_series_point_file(nQuarters, Centralbank$LIQUIDITY_BANKS, "Quarters", "Bank Liquidity", "Central Bank", "CentralBankLiquidityBanks.png", isgrid = TRUE, ltype = "o")
plot_time_series_point_file(nQuarters, Centralbank$LIQUIDITY_GOVERNMENT, "Quarters", "Government Liquidity", "Central Bank", "CentralBankLiquidityGovernment.png", isgrid = TRUE, ltype = "o")
plot_time_series_point_file(nQuarters, Centralbank$LIQUIDITY_EQUITYFUND, "Quarters", "Equity Fund Liquidity", "Central Bank", "CentralBankLiquidityEquityFund.png", isgrid = TRUE, ltype = "o")



#Government
plot_time_series_point_file(nQuarters, Government$UNEMPLOYMENT_RATE, "Quarters", "Unemployment Rate", "Government", "GovernmentUnemploymentRate.png", isgrid = TRUE, ltype = "o")
plot_time_series_point_file(nQuarters, Government$UNEMPLOYMENT_BENEFITS, "Quarters", "Unemployment Benefits", "", "GovernmentBenefitsUnemployment.png", isgrid = TRUE, ltype = "o")
plot_time_series_point_file(nQuarters, Government$GENERAL_BENEFITS, "Quarters", "General Benefits", "Government", "GovernmentBenefitsGeneral.png", isgrid = TRUE, ltype = "o")
plot_time_series_point_file(nQuarters, Government$AVERAGE_WAGE, "Quarters", "Average Wage", "", "GovernmentAverageWage.png", isgrid = TRUE, ltype = "o")
plot_time_series_point_file(nQuarters, Government$DEBT, "Quarters", "Amount", "Government Debt to Central Bank", "GovernmentDebt.png", isgrid = TRUE, ltype = "o")
plot_time_series_point_file(nQuarters, Government$CENTRALBANK_INCOME, "Quarters", "Amount", "Government Central Bank Incomes", "GovernmentCentralbankIncome.png", isgrid = TRUE, ltype = "o")
plot_time_series_point_file(nQuarters, Government$LIQUIDITY, "Quarters", "Amount", "Government Liquidity", "GovernmentLiquidity.png", isgrid = TRUE, ltype = "o")
plot_time_series_multiline_point_file(nQuarters, Government$LABOUR_TAX_RATE, Government$GOV_GENERAL_BENEFIT_RATE, "Quarters", "Rates", "Government - Fiscal Policy Rates", "GovernmentRates.png", c("Tax Rates", "Benefit Rates"), isgrid = TRUE)


#Equity Fund
plot_time_series_point_file(nQuarters, Equityfund$DIVIDENDS_RECIEVED, "Quarters", "Amount", "Equity Fund - Dividends Received", "FundDividendsReceived.png", isgrid = TRUE, ltype = "o")
plot_time_series_point_file(nQuarters, Equityfund$DIVIDENDS_RETAINED, "Quarters", "Amount", "Equity Fund - Dividends Retained", "FundDividendsRetained.png", isgrid = TRUE, ltype = "o")
plot_time_series_point_file(nQuarters, Equityfund$LIQUIDITY, "Quarters", "Amount", "Equity Fund - Liquidity", "FundLiquidity.png", isgrid = TRUE, ltype = "o")
plot_time_series_point_file(nQuarters, Equityfund$DIVIDENDS_PAID, "Quarters", "Amount", "Equity Fund - Dividends Paid", "FundDividendsPaid.png", isgrid = TRUE, ltype = "o")

plot_time_series_multiline_point_file(nQuarters, Equityfund$SHARE_FIRMS, Equityfund$SHARE_CONSTRUCTION_FIRMS, v3 = Equityfund$SHARE_BANKS, "Quarters", "Amount", "Equity Fund - Dividends Received Components", "FundDividendsReceivedParts.png", c("Firms", "CFirms", "Banks"))