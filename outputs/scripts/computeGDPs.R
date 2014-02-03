cfirmvector <- CFirmMonthly$PRODUCTION_CURRENT * CFirmMonthly$UNIT_HOUSE_PRICE
firmvector <- FirmMonthly$PRODUCTION_CURRENT * FirmMonthly$UNIT_GOODS_PRICE
efirmvector <- EFirmMonthly$PRODUCTION_CURRENT * EFirmMonthly$UNIT_XGOODS_PRICE

plot_gdp_to_file_v1(nMonths, FirmMonthly$IT_NO,firmvector, CFirmMonthly$IT_NO, cfirmvector, gtype = "Nominal", beta = betaval)
cfirmvector_real <- CFirmMonthly$PRODUCTION_CURRENT * CFirmMonthly$UNIT_HOUSE_PRICE[1]
firmvector_real <- FirmMonthly$PRODUCTION_CURRENT * FirmMonthly$UNIT_GOODS_PRICE[1]
efirmvector_real <- EFirmMonthly$PRODUCTION_CURRENT * EFirmMonthly$UNIT_XGOODS_PRICE[1]

plot_gdp_to_file_v1(nMonths, FirmMonthly$IT_NO,firmvector_real, CFirmMonthly$IT_NO, cfirmvector_real, gtype = "Real", beta = betaval)
plot_gdp_to_file_v3(nMonths, FirmMonthly$IT_NO,firmvector, CFirmMonthly$IT_NO, cfirmvector, firmvector_real, cfirmvector_real, beta = betaval)
