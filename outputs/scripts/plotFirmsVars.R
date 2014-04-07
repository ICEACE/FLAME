# Regular and Cunstructor Firms
plot_time_series_mean_file(nFirms, nQuarters, FirmBalance$UNIT_GOODS_PRICE, "Quarters", "Price (mean)", "Firms", "FirmsUnitGoodPrices.png", isgrid = TRUE, ispoint = TRUE)
plot_time_series_mean_file(nCFirms, nQuarters, CFirmBalance$UNIT_HOUSE_PRICE, "Quarters", "Price (mean)", "Constructor Firms", "CFirmsUnitHousePrices.png", isgrid = TRUE, ispoint = TRUE)

plot_time_series_mean_file(nFirms, nQuarters, FirmIncome$REVENUES, "Quarters", "Sale Revenues (mean)", "Firms", "FirmsRevenues.png", isgrid = TRUE, ispoint = TRUE)
plot_time_series_mean_file(nCFirms, nQuarters, CFirmIncome$REVENUES, "Quarters", "Sale Revenues (mean)", "Constructor Firms", "CFirmsRevenues.png", isgrid = TRUE, ispoint = TRUE)

plot_time_series_mean_file(nFirms, nQuarters, FirmIncome$LABOUR_COSTS, "Quarters", "Labour Costs (mean)", "Firms", "FirmsLabourCosts.png", isgrid = TRUE, ispoint = TRUE)
plot_time_series_mean_file(nCFirms, nQuarters, CFirmIncome$LABOUR_COSTS, "Quarters", "Labour Costs (mean)", "Constructor Firms", "CFirmsLabourCosts.png", isgrid = TRUE, ispoint = TRUE)

plot_time_series_mean_file(nFirms, nQuarters, FirmIncome$TOTAL_INTEREST_PAYMENTS, "Quarters", "Loan Interest Payments (mean)", "Firms", "FirmsInterestPayments.png", isgrid = TRUE, ispoint = TRUE)
plot_time_series_mean_file(nCFirms, nQuarters, CFirmIncome$TOTAL_INTEREST_PAYMENTS, "Quarters", "Loan Interest Payments (mean)", "Constructor Firms", "CFirmsInterestPayments.png", isgrid = TRUE, ispoint = TRUE)

plot_time_series_mean_file(nFirms, nQuarters, FirmIncome$NET_EARNINGS, "Quarters", "Net Earnings (mean)", "Firms", "FirmsNetEarnings.png", isgrid = TRUE, ispoint = TRUE)
plot_time_series_mean_file(nCFirms, nQuarters, CFirmIncome$NET_EARNINGS, "Quarters", "Net Earnings (mean)", "Constructor Firms", "CFirmsNetEarnings.png", isgrid = TRUE, ispoint = TRUE)

plot_time_series_mean_file(nFirms, nQuarters, FirmIncome$EBIT, "Quarters", "EBIT (mean)", "Firms", "FirmsEBIT.png", isgrid = TRUE, ispoint = TRUE)
plot_time_series_mean_file(nCFirms, nQuarters, CFirmIncome$EBIT, "Quarters", "EBIT (mean)", "Constructor Firms", "CFirmsEBIT.png", isgrid = TRUE, ispoint = TRUE)

plot_time_series_mean_file(nFirms, nQuarters, FirmBalance$TOTAL_ASSETS, "Quarters", "Total Assets (mean)", "Firms", "FirmsTotalAssets.png", isgrid = TRUE, ispoint = TRUE)
plot_time_series_mean_file(nCFirms, nQuarters, CFirmBalance$TOTAL_ASSETS, "Quarters", "Total Assets (mean)", "Constructor Firms", "CFirmsTotalAssets.png", isgrid = TRUE, ispoint = TRUE)

plot_time_series_mean_file(nFirms, nQuarters, FirmBalance$LIQUIDITY, "Quarters", "Liquidity (mean)", "Firms", "FirmsLiquidity.png", isgrid = TRUE, ispoint = TRUE)
plot_time_series_mean_file(nCFirms, nQuarters, CFirmBalance$LIQUIDITY, "Quarters", "Liquidity (mean)", "Constructor Firms", "CFirmsLiquidity.png", isgrid = TRUE, ispoint = TRUE)

plot_time_series_mean_file(nFirms, nQuarters, FirmBalance$DEBT, "Quarters", "Debt (mean)", "Firms", "FirmsDebt.png", isgrid = TRUE, ispoint = TRUE)

plot_time_series_mean_file(nCFirms, nQuarters, CFirmBalance$DEBT, "Quarters", "Debt (mean)", "Constructor Firms", "CFirmsDebt.png", isgrid = TRUE, ispoint = TRUE)

plot_time_series_mean_file(nFirms, nQuarters, FirmBalance$EQUITY, "Quarters", "Equity (mean)", "Firms", "FirmsEquity.png", isgrid = TRUE, ispoint = TRUE)

plot_time_series_mean_file(nCFirms, nQuarters, CFirmBalance$EQUITY, "Quarters", "Equity (mean)", "Constructor Firms", "CFirmsEquity.png", isgrid = TRUE, ispoint = TRUE)

plot_time_series_mean_file(nFirms, nQuarters, FirmBalance$CAPITAL_GOODS, "Quarters", "Capital Goods (mean)", "Firms", "FirmsCapitalGoods.png", isgrid = TRUE, ispoint = TRUE)
plot_time_series_mean_file(nCFirms, nQuarters, CFirmBalance$CAPITAL_GOODS, "Quarters", "Capital Goods (mean)", "Constructor Firms", "CFirmsCapitalGoods.png", isgrid = TRUE, ispoint = TRUE)

plot_time_series_mean_file_v2(nQuarters, FirmDividends$IT_NO, FirmDividends$DIVIDENDS_PAID, "Quarters", "Dividends Paid (mean)", "Firms", "FirmsDividendsPaid.png", ispoint = TRUE, cycle = 60)
plot_time_series_mean_file_v2(nQuarters, CFirmDividends$IT_NO, CFirmDividends$DIVIDENDS_PAID, "Quarters", "Dividends Paid (mean)", "Constructor Firms", "CFirmsDividendsPaid.png", ispoint = TRUE, cycle = 60)

plot_time_series_mean_file_v2(nMonths, FirmMonthly$IT_NO, FirmMonthly$NO_EMPLOYEES, "Months", "No Employees (mean)", "Firms", "FirmsEmployeeSize.png", ispoint = TRUE)
plot_time_series_mean_file_v2(nMonths, CFirmMonthly$IT_NO, CFirmMonthly$NO_EMPLOYEES, "Months", "No Employees (mean)", "Constructor Firms", "CFirmsEmployeeSize.png", ispoint = TRUE)

plot_time_series_mean_file_v2(nMonths, FirmMonthly$IT_NO, FirmMonthly$INVENTORY, "Months", "Inventory (mean)", "Firms", "FirmsInventory.png", ispoint = TRUE)
plot_time_series_mean_file_v2(nMonths, CFirmMonthly$IT_NO, CFirmMonthly$INVENTORY, "Months", "Inventory (mean)", "Constructor Firms", "CFirmsInventory.png", ispoint = TRUE)

plot_time_series_mean_file_v2(nMonths, FirmMonthly$IT_NO, FirmMonthly$PRODUCTION_PLAN, "Months", "Production Plan (mean)", "Firms", "FirmsProductionPlan.png", ispoint = TRUE)
plot_time_series_mean_file_v2(nMonths, CFirmMonthly$IT_NO, CFirmMonthly$PRODUCTION_PLAN, "Months", "Production Plan (mean)", "Constructor Firms", "CFirmsProductionPlan.png", ispoint = TRUE)

plot_time_series_mean_file_v2(nMonths, FirmMonthly$IT_NO, FirmMonthly$PRODUCTION_CURRENT, "Months", "Production Current (mean)", "Firms", "FirmsProductionCurrent.png", ispoint = TRUE)
plot_time_series_mean_file_v2(nMonths, CFirmMonthly$IT_NO, CFirmMonthly$PRODUCTION_CURRENT, "Months", "Production Current (mean)", "Constructor Firms", "CFirmsProductionCurrent.png", ispoint = TRUE)

plot_time_series_mean_file_v2(nMonths, FirmMonthly$IT_NO, FirmMonthly$SALES, "Months", "Sales (mean)", "Firms", "FirmsSales.png", ispoint = TRUE)

plot_time_series_mean_file_v2(nMonths, CFirmMonthly$IT_NO, CFirmMonthly$SALES, "Months", "Sales (mean)", "Constructor Firms", "CFirmsSales.png", ispoint = TRUE)

#### Export Firms ###

plot_time_series_mean_file(nEFirms, nQuarters, EFirmBalance$UNIT_XGOODS_PRICE, "Quarters", "Price (mean)", "Exporter Firms", "EFirmsUnitXGoodsPrices.png", isgrid = TRUE, ispoint = TRUE)

plot_time_series_mean_file(nEFirms, nQuarters, EFirmBalance$TOTAL_ASSETS, "Quarters", "Total Assets (mean)", "Exporter Firms", "EFirmsTotalAssets.png", isgrid = TRUE, ispoint = TRUE)

plot_time_series_mean_file(nEFirms, nQuarters, EFirmBalance$LIQUIDITY, "Quarters", "Liquidity (mean)", "Exporter Firms", "EFirmsLiquidity.png", isgrid = TRUE, ispoint = TRUE)


plot_time_series_mean_file(nEFirms, nQuarters, EFirmBalance$DEBT, "Quarters", "Debt (mean)", "Exporter Firms", "EFirmsDebt.png", isgrid = TRUE, ispoint = TRUE)

plot_time_series_mean_file(nEFirms, nQuarters, EFirmBalance$EQUITY, "Quarters", "Equity (mean)", "Exporter Firms", "EFirmsEquity.png", isgrid = TRUE, ispoint = TRUE)

plot_time_series_mean_file(nEFirms, nQuarters, EFirmBalance$CAPITAL_GOODS, "Quarters", "Capital Goods (mean)", "Exporter Firms", "EFirmsCapitalGoods.png", isgrid = TRUE, ispoint = TRUE)

plot_time_series_mean_file(nEFirms, nQuarters, EFirmIncome$REVENUES, "Quarters", "Sale Revenues (mean)", "Exporter Firms", "EFirmsRevenues.png", isgrid = TRUE, ispoint = TRUE)

plot_time_series_mean_file(nEFirms, nQuarters, EFirmIncome$LABOUR_COSTS, "Quarters", "Labour Costs (mean)", "Exporter Firms", "EFirmsLabourCosts.png", isgrid = TRUE, ispoint = TRUE)

plot_time_series_mean_file(nEFirms, nQuarters, EFirmIncome$TOTAL_INTEREST_PAYMENTS, "Quarters", "Loan Interest Payments (mean)", "Exporter Firms", "EFirmsInterestPayments.png", isgrid = TRUE, ispoint = TRUE)

plot_time_series_mean_file(nEFirms, nQuarters, EFirmIncome$NET_EARNINGS, "Quarters", "Net Earnings (mean)", "Exporter Firms", "EFirmsNetEarnings.png", isgrid = TRUE, ispoint = TRUE)

plot_time_series_mean_file(nEFirms, nQuarters, EFirmIncome$EBIT, "Quarters", "EBIT (mean)", "Exporter Firms", "EFirmsEBIT.png", isgrid = TRUE, ispoint = TRUE)

plot_time_series_mean_file_v2(nQuarters, EFirmDividends$IT_NO, EFirmDividends$DIVIDENDS_PAID, "Quarters", "Dividends Paid (mean)", "Exporter Firms", "EFirmsDividendsPaid.png", ispoint = TRUE, cycle = 60)


plot_time_series_mean_file_v2(nMonths, EFirmMonthly$IT_NO, EFirmMonthly$NO_EMPLOYEES, "Months", "No Employees (mean)", "Exporter Firms", "EFirmsEmployeeSize.png", ispoint = TRUE)

plot_time_series_mean_file_v2(nMonths, EFirmMonthly$IT_NO, EFirmMonthly$INVENTORY, "Months", "Inventory (mean)", "Exporter Firms", "EFirmsInventory.png", ispoint = TRUE)

plot_time_series_mean_file_v2(nMonths, EFirmMonthly$IT_NO, EFirmMonthly$PRODUCTION_PLAN, "Months", "Production Plan (mean)", "Exporter Firms", "EFirmsProductionPlan.png", ispoint = TRUE)

plot_time_series_mean_file_v2(nMonths, EFirmMonthly$IT_NO, EFirmMonthly$PRODUCTION_CURRENT, "Months", "Production Current (mean)", "Exporter Firms", "EFirmsProductionCurrent.png", ispoint = TRUE)


plot_time_series_mean_file_v2(nMonths, EFirmMonthly$IT_NO, EFirmMonthly$SALES, "Months", "Sales (mean)", "Exporter Firms", "EFirmsSales.png", ispoint = TRUE)


