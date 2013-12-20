### Households ###

#Household - Quarterly
boxplot_time_series_distro_file(nHouseholds, nQuarters, HouseholdQuarterly$TOTAL_ASSETS, "Quarters", "Total Assets (boxplot)", "Households", "HouseholdsTotalAssetsDistro.png")
plot_time_series_mean_file(nHouseholds, nQuarters, HouseholdQuarterly$TOTAL_ASSETS, "Quarters", "Total Assests (mean)", "Households", "HouseholdsTotalAssetsMean.png", isgrid = TRUE, ispoint = TRUE)

boxplot_time_series_distro_file(nHouseholds, nQuarters, HouseholdQuarterly$HOUSING_VALUE, "Quarters", "Housing Value (boxplot)", "Households", "HouseholdsHousingValueDistro.png")
plot_time_series_mean_file(nHouseholds, nQuarters, HouseholdQuarterly$HOUSING_VALUE, "Quarters", "Housing Value (mean)", "Households", "HouseholdsHousingValueMean.png", isgrid = TRUE, ispoint = TRUE)

boxplot_time_series_distro_file(nHouseholds, nQuarters, HouseholdQuarterly$LIQUIDITY, "Quarters", "Household Liquidity (boxplot)", "Households", "HouseholdsLiquidityQuarterlyDistro.png")
plot_time_series_mean_file(nHouseholds, nQuarters, HouseholdQuarterly$LIQUIDITY, "Quarters", "Household Liquidity (mean)", "Households", "HouseholdsLiquidityQuarterlyMean.png", isgrid = TRUE, ispoint = TRUE)

boxplot_time_series_distro_file(nHouseholds, nQuarters, HouseholdQuarterly$EQUITY, "Quarters", "Equity (boxplot)", "Households", "HouseholdsEquityDistro.png")
plot_time_series_mean_file(nHouseholds, nQuarters, HouseholdQuarterly$EQUITY, "Quarters", "Equity (mean)", "Households", "HouseholdsEquityMean.png", isgrid = TRUE, ispoint = TRUE)

boxplot_time_series_distro_file(nHouseholds, nQuarters, HouseholdQuarterly$MORTGAGES, "Quarters", "Mortgages (boxplot)", "Households", "HouseholdsMortgagesDistro.png")
plot_time_series_mean_file(nHouseholds, nQuarters, HouseholdQuarterly$MORTGAGES, "Quarters", "Mortgages (mean)", "Households", "HouseholdsMortgagesMean.png", isgrid = TRUE, ispoint = TRUE)

boxplot_time_series_distro_file(nHouseholds, nQuarters, HouseholdQuarterly$LABOUR_INCOME, "Quarters", "Labour Income (boxplot)", "Households", "HouseholdsLabourIncomeDistro.png")
plot_time_series_mean_file(nHouseholds, nQuarters, HouseholdQuarterly$LABOUR_INCOME, "Quarters", "Labour Income (mean)", "Households", "HouseholdsLabourIncomeMean.png", isgrid = TRUE, ispoint = TRUE)

boxplot_time_series_distro_file(nHouseholds, nQuarters, HouseholdQuarterly$CAPITAL_INCOME, "Quarters", "Capital Income (boxplot)", "Households", "HouseholdsCapitalIncomeDistro.png")
plot_time_series_mean_file(nHouseholds, nQuarters, HouseholdQuarterly$CAPITAL_INCOME, "Quarters", "Capital Income (mean)", "Households", "HouseholdsCapitalIncomeMean.png", isgrid = TRUE, ispoint = TRUE)

boxplot_time_series_distro_file(nHouseholds, nQuarters, HouseholdQuarterly$HOUSING_PAYMENT, "Quarters", "Housing Payment (boxplot)", "Households", "HouseholdsHousingPaymentDistro.png")
plot_time_series_mean_file(nHouseholds, nQuarters, HouseholdQuarterly$HOUSING_PAYMENT, "Quarters", "Housing Payment (mean)", "Households", "HouseholdsHousingPaymentMean.png", isgrid = TRUE, ispoint = TRUE)

boxplot_time_series_distro_file(nHouseholds, nQuarters, HouseholdQuarterly$BENEFITS, "Quarters", "Total Benefits (boxplot)", "Households", "HouseholdsBenefitsDistro.png")
plot_time_series_mean_file(nHouseholds, nQuarters, HouseholdQuarterly$BENEFITS, "Quarters", "Total Benefits (mean)", "Households", "HouseholdsBenefitsMean.png", isgrid = TRUE, ispoint = TRUE)


#Household - Monthly
plot_time_series_mean_file(nHouseholds, nMonths, HouseholdMonthlyFirst$LIQUIDITY, "Months", "Liquidity (mean)", "Households", "HouseholdsLiquidityMonthly.png", ispoint = TRUE)
plot_time_series_mean_file(nHouseholds, nMonths, HouseholdMonthlyFirst$MORTGAGES, "Months", "Mortgages (mean)", "Households", "HouseholdsMortgagesMonthly.png", ispoint = TRUE)
plot_time_series_mean_file(nHouseholds, nMonths, HouseholdMonthlyFirst$MORTGAGE_COST, "Months", "Mortgage Costs (mean)", "Households", "HouseholdsMortgageCostsMonthly.png", ispoint = TRUE)
plot_time_series_mean_file(nHouseholds, nMonths, HouseholdMonthlyFirst$HOUSING_UNITS, "Months", "Housing Units (mean)", "Households", "HouseholdsHousingUnitsMonthly.png", ispoint = TRUE)
plot_time_series_mean_file(nHouseholds, nMonths, HouseholdMonthlyFirst$HOUSING_VALUE, "Months", "Housing Value (mean)", "Households", "HouseholdsHousingValuesMonthly.png", ispoint = TRUE)
plot_time_series_mean_file(nHouseholds, nMonths, HouseholdMonthlyFirst$EQUITY_RATIO, "Months", "Eqquity Ratio (mean)", "Households", "HouseholdsEquityRatioMonthly.png", ispoint = TRUE)


#Household - Weekly
plot_time_series_mean_file(nFirms, nWeeks, HouseholdWeekly$LIQUIDITY, "Weeks", "Liquidity (mean)", "Households", "HouseholdsLiquidityWeekly.png")
plot_time_series_mean_file(nHouseholds, nWeeks, HouseholdWeekly$money_to_spend, "Weeks", "Money Available to Spend (mean)", "Households", "HouseholdsMoneyToSpendWeekly.png")
plot_time_series_mean_file(nHouseholds, nWeeks, HouseholdWeekly$money_spent, "Weeks", "Money Spent (mean)", "Households", "HouseholdsMoneySpentWeekly.png")
