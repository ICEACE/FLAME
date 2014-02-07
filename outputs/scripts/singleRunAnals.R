### Init Workspace  ###
rm(list = ls())
source("/Users/bulent/Documents/AWorkspace/iceace/FLAME/outputs/scripts/LibIceace.R", echo = TRUE)
data_dir = "/Users/bulent/Documents/AWorkspace/iceace/FLAME/outputs/data"
output_dir = "/Users/bulent/Documents/AWorkspace/iceace/FLAME/outputs/plots/"
setwd(output_dir)

# Import Datasets #
data_household = 1
source("/Users/bulent/Documents/AWorkspace/iceace/FLAME/outputs/scripts/importSimResults.R", echo = T)

# Plotting Mall, Real Estate, Government, Central Bank and Equity Fund Vars #
source("/Users/bulent/Documents/AWorkspace/iceace/FLAME/outputs/scripts/plotAgentVars.R", echo = T)


# Plot Bank Vars #
bankA = 22
bankB = 23
source("/Users/bulent/Documents/AWorkspace/iceace/FLAME/outputs/scripts/plotBanksVars.R", echo = T)

# Plot Firm Vars #
source("/Users/bulent/Documents/AWorkspace/iceace/FLAME/outputs/scripts/plotFirmsVars.R", echo = T)


# Compute Writeoff Cases #
niter = 3600
source("/Users/bulent/Documents/AWorkspace/iceace/FLAME/outputs/scripts/computeWriteoffs.R", echo = T)

# Compute Crediting Frequencies #
source("/Users/bulent/Documents/AWorkspace/iceace/FLAME/outputs/scripts/computeCreditings.R", echo = T)


# Compute Housing Market Activities#
source("/Users/bulent/Documents/AWorkspace/iceace/FLAME/outputs/scripts/computeHousing.R", echo = T)

# Plot Household Vars #
if (data_household){
	source("/Users/bulent/Documents/AWorkspace/iceace/FLAME/outputs/scripts/plotHouseholdVars.R", echo = T)
	}


# Compute GDP #
betaval = "0.30"
source("/Users/bulent/Documents/AWorkspace/iceace/FLAME/outputs/scripts/computeGDPs.R", echo = T)

# Identity Checks
source("/Users/bulent/Documents/AWorkspace/iceace/FLAME/outputs/scripts/identityCheck.R", echo = T)
