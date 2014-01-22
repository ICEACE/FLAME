boxplot_time_series_distro_file <- function(nagents, niter, datavector, xlabel, ylabel, title, fname){
	png(fname, width = 1500, height = 800, pointsize=24)
	times <- (1:niter)
	values <- matrix(datavector, nrow = niter, ncol = nagents, byrow = T)
	boxplot(values~times, type="l", col = "blue", lwd = 3, xlab = xlabel, ylab=ylabel, main = title)
	dev.off()
}

boxplot_experiments_to_file <- function(niter, exps, xlabel, ylabel, title, fname){
	png(fname, width = 1500, height = 800, pointsize=24)
	iters <- (1:niter)
	boxplot(exps~iters, type="l", col = "blue", lwd = 3, xlab = xlabel, ylab=ylabel, main = title)
	dev.off()
}


plot_mean_experiments_to_file <- function(niter, exps, xlabel, ylabel, title, fname){
	png(fname, width = 1500, height = 800, pointsize=24)
	iters <- (1:niter)
	plot(exps~iters, type="l", col = "blue", lwd = 3, xlab = xlabel, ylab=ylabel, main = title)
	dev.off()
}


plot_time_series_mean_file <- function(nagents, niter, datavector, xlabel, ylabel, title, fname, isgrid = FALSE, ispoint = FALSE){
	png(fname, width = 1500, height = 800, pointsize=24)
	times <- (1:niter)
	means <- rep(0,niter)
	values <- matrix(datavector, nrow = niter, ncol = nagents, byrow = T)
	for (i in 1:niter){
		means[i] <- mean(values[i,])
	}
	plot(means~times, type="n", xlab = xlabel, ylab=ylabel, main = title)
	if (isgrid){
		abline(v = times, h = means, col = "lightgray", lty = "dotted", lwd = 2)	
	}
	lines(means~times, type="l", col = "blue", lwd = 3)
	if (ispoint){
		points(means~times, pch = 16, col = "blue")
	}
	dev.off()
}

plot_time_series_mean_file_v2 <- function(niter, itervector, memoryvector, xlabel, ylabel, title, fname, isgrid = FALSE, ispoint = FALSE, cycle = 20, phase = 1){
	times <- (1:niter)
	means <- rep(0,niter)
	current_iter <- itervector[1]
	datalength <- length(memoryvector)
	accumulator <- 0
	nvals <- 0
	for (i in 1:datalength){
		if (itervector[i] != current_iter){
			ind <- (current_iter - phase)/cycle + 1
			means[ind] <- accumulator / nvals
			nvals <- 0
			accumulator <- 0
			current_iter <- itervector[i]	
		}
		nvals <- nvals + 1
		accumulator <- accumulator + memoryvector[i]
	}
	ind <- (current_iter - phase)/cycle + 1
	means[ind] <- accumulator / nvals
	png(fname, width = 1500, height = 800, pointsize=24)
	plot(means~times, type="n", xlab = xlabel, ylab=ylabel, main = title)
	if (isgrid){
		abline(v = times, h = means, col = "lightgray", lty = "dotted", lwd = 3)	
	}
	lines(means~times, type="l", col = "blue", lwd = 3)
	if (ispoint){
		points(means~times,  col = "blue", pch = 16)
	}
	dev.off()
}


plot_time_series_point_file <- function(niter, datavector, xlabel, ylabel, title, fname, isgrid = FALSE, ltype = "l", ispoint = F){
	png(fname, width = 1500, height = 800, pointsize=24)
	times <- (1:niter)
	plot(datavector~times, type="n", xlab = xlabel, ylab=ylabel, main = title)
	if (isgrid){
		abline(v = times, h = datavector, col = "lightgray", lty = "dotted", lwd = 2)
		}
	lines(datavector~times, type=ltype, col = "blue", lwd = 2)
	if (ispoint){
		points(datavector~times,  col = "blue", pch = 16)
	}
	dev.off()
}

plot_time_series_multiline_point_file <- function(niter, v1, v2, xlabel, ylabel, title, fname, legends, v3=vector(), v4 =vector(), legposn = "topleft", isgrid = FALSE, ptype = "l", ispoint = T, maxv = FALSE, minv = FALSE){
	times <- (1:niter)
	valrange <- v1
	#minval <- floor(min(c(v1,v2,v3,v4)))
	minval <- min(c(v1,v2,v3,v4))
	if (minv){
		minval <- min(c(minval, minv))
	}
	valrange[1] <- minval
	#maxval <- ceiling(max(c(v1,v2,v3,v4)))
	maxval <- max(c(v1,v2,v3,v4))
	if (maxv){
		maxval <- max(c(maxval, maxv))
	}

	valrange[-1] <- maxval
	png(fname, width = 1500, height = 800, pointsize=18)
	plot(valrange~times, type="n", xlab = xlabel, ylab=ylabel, main = title)
	if (isgrid){
		#grid(nx = niter, ny = ceiling(maxval), col = "lightgray", lty = "dotted", lwd = 2)
		abline(v = times, h = (minval:maxval), col = "lightgray", lty = "dotted", lwd = 2)
		}
	lines(v1~times, type=ptype, col="red", lwd=3)
	lines(v2~times, type=ptype, col="blue", lwd=3)
	if (length(v4) > 1){
		lines(v3~times, type=ptype, col="black", lwd=3)
		lines(v4~times, type=ptype, col="green", lwd=3)	
		legend(legposn, legends, lty = c(1,1,1,1), lwd = c(3,3,3,3), col = c("red", "blue", "black", "green"))
		if (ispoint) {
			points(v1~times)
			points(v2~times)
			points(v3~times)
			points(v4~times)
			}
	}
	else if (length(v3) > 1) {
		lines(v3~times, type=ptype, col="black", lwd=3)	
		legend(legposn, legends, lty = c(1,1,1), lwd = c(3,3,3), col = c("red", "blue", "black"))
		if (ispoint) {
			points(v1~times)
			points(v2~times)
			points(v3~times)
			}
	}
	else{
		legend(legposn, legends, lty = c(1,1), lwd = c(3,3), col = c("red", "blue"))
		if (ispoint){
			points(v1~times)
			points(v2~times)
			}
		}
	dev.off()
}

get_experiment_data_set <-function(data_dir, data_file){
	exps <- list.files(data_dir)
	n_exps <- length(exps)
	dataSet <- list()
	for (i in 1:n_exps){
		filename = paste(data_dir,list.files(data_dir)[i], '/', data_file, sep ='')
		dataSet[[i]] <- read.csv(filename, sep = " ", header = T, stringsAsFactors = F)
	}
	return(dataSet)
}

get_points_set <- function(nexps, dataSet, memVar){
	means <- dataSet[[1]][memVar]
	if (nexps < 2){
		return(means)
		}
	for (i in 2:nexps){
		means <- cbind(means, dataSet[[i]][memVar]) 
	}
	return(as.matrix(means))
}

get_mean_of_experiments <- function(niters, datamatrix){
	times <- (1:niters)
	mean <- (1:niters)
	for (i in 1:niters){
		mean[i] <- mean(datamatrix[i,]) 
	}
	return(mean)
}

plot_mean_experiments <- function(niter, exps){
	iters <- (1:niter)
	plot(exps~iters, type="l")
}

boxplot_experiments <- function(niter, exps){
	iters <- (1:niter)
	boxplot(exps~iters, type="l")
}

get_means <- function(nagents, niter, datavector){
	times <- (1:niter)
	means <- (1:niter)
	values <- matrix(datavector, nrow = niter, ncol = nagents, byrow = T)
	for (i in 1:niter){
		means[i] <- mean(values[i,])
	}
	return(means)
}

get_medians <- function(nagents, niter, datavector){
	times <- (1:niter)
	medians <- (1:niter)
	values <- matrix(datavector, nrow = niter, ncol = nagents, byrow = T)
	for (i in 1:niter){
		medians[i] <- median(values[i,])
	}
	return(medians)
}

get_means_set <- function(nexps, dataSet, memVar, nagents, niter){
	means <- get_means(nagents, niter, dataSet[[1]][memVar][,1])
	if (nexps < 2){
		return(as.matrix(means))
		}	
	meansSet = means
	for (i in 2:nexps){
		means <- get_means(nagents, niter, dataSet[[i]][memVar][,1])
		meansSet <- cbind(meansSet, means) 
	}
	return(as.matrix(meansSet))
}



plot_gdp_to_file_v1 <- function(niter, firmiters, firmvector, cfirmiters, cfirmvector, gtype = "Nominal", beta = "0.3"){
	times <- (1:niter)
	fsums <- (1:niter)
	csums <- (1:niter)
	gdp <- (1:niter)
	
	#Regular Firm productions
	current_iter <- firmiters[1]
	datalength <- length(firmvector)
	accumulator <- 0
	ind <- 1
	for (i in 1:datalength){
		if (firmiters[i] != current_iter){
			fsums[ind] <- accumulator
			ind <- ind + 1
			accumulator <- 0
			current_iter <- firmiters[i]	
		}
		accumulator <- accumulator + firmvector[i]
	}
	fsums[ind] <- accumulator

    #constructor Firm productions
	current_iter <- cfirmiters[1]
	datalength <- length(cfirmvector)
	accumulator <- 0
	ind <- 1
	for (i in 1:datalength){
		if (cfirmiters[i] != current_iter){
			csums[ind] <- accumulator
			ind <- ind + 1
			accumulator <- 0
			current_iter <- cfirmiters[i]	
		}
		accumulator <- accumulator + cfirmvector[i]
	}
	csums[ind] <- accumulator
	
	for (i in 1:niter){
		gdp[i] <- fsums[i] + csums[i]
	}
	fname = paste("aGDP_", gtype, "_Monthly.png", sep = "")
	ylabtext = paste("GDP (Total Production Market Value - ", gtype, sep = "")
	title = paste("Beta = ", beta, sep = "")
	png(fname, width = 1500, height = 800, pointsize=18)
	plot(gdp~times, type="n", xlab = "Months", ylab=ylabtext, main = title)
	abline(v = times, h = gdp, col = "lightgray", lty = "dotted", lwd = 1)
	lines(gdp~times, type="l", col = "blue", lwd = 3)
	points(gdp~times,  col = "blue", pch = 16)
	dev.off()
	
	nquarters = niter / 3
	quarters <- (1:nquarters)
	gdpquarters <- (1:nquarters)
	accumulator <- 0
	ind <- 1
	for (i in 1:niter){
		if (i %% 3 == 0){
			accumulator <- accumulator + gdp[i]
			gdpquarters[ind] <- accumulator
			ind <- ind + 1
			accumulator <- 0
			}
		else{
			accumulator <- accumulator + gdp[i]
			}
	}
	fname = paste("aGDP_", gtype, "_Quarterly.png", sep = "")
	png(fname, width = 1500, height = 800, pointsize=18)
	plot(gdpquarters~quarters, type="n", xlab = "Quarters", ylab=ylabtext, main = title)
	abline(v = quarters, h = gdpquarters, col = "lightgray", lty = "dotted", lwd = 2)
	lines(gdpquarters~quarters, type="l", col = "blue", lwd = 3)
	points(gdpquarters~quarters,  col = "blue", pch = 16)
	dev.off()

	
	nyears = niter / 12
	years <- (1:nyears)
	gdpyears <- (1:nyears)
	accumulator <- 0
	ind <- 1
	for (i in 1:niter){
		if (i %% 12 == 0){
			accumulator <- accumulator + gdp[i]
			gdpyears[ind] <- accumulator
			ind <- ind + 1
			accumulator <- 0
			}
		else{
			accumulator <- accumulator + gdp[i]
			}
	}
	
	fname = paste("aGDP_", gtype, "_Yearly.png", sep = "")
	png(fname, width = 1500, height = 800, pointsize=18)
	plot(gdpyears~years, type="n", xlab = "Years", ylab=ylabtext, main = title)
	abline(v = years, h = gdpyears, col = "lightgray", lty = "dotted", lwd = 3)
	lines(gdpyears~years, type="l", col = "blue", lwd = 3)
	points(gdpyears~years,  col = "blue", pch = 16)
	dev.off()
	return(gdpyears)
}

plot_gdp_to_file_v2 <- function(niter, firmiters, firmvector, cfirmiters, cfirmvector, Rfirmvector, Rcfirmvector, beta = "0.3"){
	times <- (1:niter)
	fsums <- rep(0,niter)
	csums <- rep(0,niter)
	gdp <- rep(0,niter)
	
	Rfsums <- rep(0,niter)
	Rcsums <- rep(0,niter)
	Rgdp <- rep(0,niter)
	
	
	#Regular Firm productions
	current_iter <- firmiters[1]
	datalength <- length(firmvector)
	accumulator <- 0
	Raccumulator <- 0
	ind <- 1
	for (i in 1:datalength){
		if (firmiters[i] != current_iter){
			fsums[ind] <- accumulator
			Rfsums[ind] <- Raccumulator
			ind <- ind + 1
			accumulator <- 0
			Raccumulator <- 0
			current_iter <- firmiters[i]	
		}
		accumulator <- accumulator + firmvector[i]
		Raccumulator <- Raccumulator + Rfirmvector[i]
	}
	fsums[ind] <- accumulator
	Rfsums[ind] <- Raccumulator

    #constructor Firm productions
	current_iter <- cfirmiters[1]
	datalength <- length(cfirmvector)
	accumulator <- 0
	Raccumulator <- 0
	ind <- 1
	for (i in 1:datalength){
		if (cfirmiters[i] != current_iter){
			csums[ind] <- accumulator
			Rcsums[ind] <- Raccumulator
			ind <- ind + 1
			accumulator <- 0
			Raccumulator <- 0
			current_iter <- cfirmiters[i]	
		}
		accumulator <- accumulator + cfirmvector[i]
		Raccumulator <- Raccumulator + Rcfirmvector[i]
	}
	csums[ind] <- accumulator
	Rcsums[ind] <- Raccumulator
	
	for (i in 1:niter){
		gdp[i] <- fsums[i] + csums[i]
		Rgdp[i] <- Rfsums[i] + Rcsums[i]
	}
	fname = "aGDP_Monthly.png"
	ylabtext = "GDP - Growth of Housing Units and Consumption Goods Production"
	title = paste("Beta = ", beta, sep = "")
	
	png(fname, width = 1500, height = 800, pointsize=18)
	valrange <- gdp
	valrange[1] <- min(Rgdp)
	plot(valrange~times, type="n", xlab = "Months", ylab=ylabtext, main = title)
	abline(v = times, h = gdp, col = "lightgray", lty = "dotted", lwd = 1)
	abline(v = times, h = Rgdp, col = "lightgray", lty = "dotted", lwd = 1)
	lines(gdp~times, type="o", col = "red", lwd = 3)
	lines(Rgdp~times, type = "o", col = "blue", lwd = 3)
	legend("topleft", c("Nominal","Real"), lty = c(1,1), lwd = c(2,2), col = c("red", "blue"))
	dev.off()
	
	nquarters = niter / 3
	quarters <- (1:nquarters)
	gdpquarters <- rep(0, nquarters)
	Rgdpquarters <- rep(0,nquarters)
	accumulator <- 0
	Raccumulator <- 0
	ind <- 1
	for (i in 1:niter){
		if (i %% 3 == 0){
			accumulator <- accumulator + gdp[i]
			Raccumulator <- Raccumulator + Rgdp[i]
			gdpquarters[ind] <- accumulator
			Rgdpquarters[ind] <- Raccumulator
			ind <- ind + 1
			accumulator <- 0
			Raccumulator <- 0
			}
		else{
			accumulator <- accumulator + gdp[i]
			Raccumulator <- Raccumulator + Rgdp[i]
			}
	}
	fname = "aGDP_Quarterly.png"
	png(fname, width = 1500, height = 800, pointsize=18)
	valrange <- gdpquarters
	valrange[1] <- min(Rgdpquarters)
	plot(valrange~quarters, type="n", xlab = "Quarters", ylab=ylabtext, main = title)
	abline(v = quarters, h = gdpquarters, col = "lightgray", lty = "dotted", lwd = 2)
	abline(v = quarters, h = Rgdpquarters, col = "lightgray", lty = "dotted", lwd = 2)
	lines(gdpquarters~quarters, type="o", col = "red", lwd = 3)
	lines(Rgdpquarters~quarters, type = "o", col = "blue", lwd = 3)
	legend("topleft", c("Nominal","Real"), lty = c(1,1), lwd = c(2,2), col = c("red", "blue"))
	dev.off()
	
	nyears = niter / 12
	years <- (1:nyears)
	gdpyears <- rep(0,nyears)
	accumulator <- 0
	Rgdpyears <- rep(0,nyears)
	Raccumulator <- 0
	ind <- 1
	for (i in 1:niter){
		if (i %% 12 == 0){
			accumulator <- accumulator + gdp[i]
			gdpyears[ind] <- accumulator
			Raccumulator <- Raccumulator + Rgdp[i]
			Rgdpyears[ind] <- Raccumulator
			ind <- ind + 1
			accumulator <- 0
			Raccumulator <- 0
			}
		else{
			accumulator <- accumulator + gdp[i]
			Raccumulator <- Raccumulator + Rgdp[i]
			}
	}
	
	fname = "aGDP_Yearly.png"
	png(fname, width = 1500, height = 800, pointsize=18)
	valrange <- gdpyears
	valrange[1] <- min(Rgdpyears)
	plot(valrange~years, type="n", xlab = "Years", ylab=ylabtext, main = title)
	abline(v = times, h = gdpyears, col = "lightgray", lty = "dotted", lwd = 3)
	abline(v = times, h = Rgdpyears, col = "lightgray", lty = "dotted", lwd = 3)
	lines(gdpyears~years, type="o", col = "red", lwd = 3)
	lines(Rgdpyears~years, type = "o", col = "blue", lwd = 3)
	legend("topleft", c("Nominal","Real"), lty = c(1,1), lwd = c(2,2), col = c("red", "blue"))
	dev.off()
	return(gdpyears)
}


plot_time_series_banks <- function(niter, idvector, bank_1, bank_2, memoryvector, xlabel, ylabel, title, fname, isgrid = FALSE, ltype = "l"){
        times <- (1:niter)
        bankA <- (1:niter)
        bankB <- (1:niter)
        indA <- 1;
        indB <- 1;
        bmin <- min(memoryvector)
        bmax <- max(memoryvector)
        valrange <- (1:niter)
        valrange[1] <- bmin
        valrange[-1] <- bmax
        datalength <- length(memoryvector)
        for (i in 1:datalength){
                if (idvector[i] == bank_1){
                        bankA[indA] <- memoryvector[i]
                        indA <- indA + 1        
                }
                else{
                        bankB[indB] <- memoryvector[i]
                        indB <- indB + 1
                        }
        }
        legA = paste("Bank ID = ", as.character(bank_1),  sep ='')
        legB = paste("Bank ID = ", as.character(bank_2),  sep ='')
        png(fname, width = 1500, height = 800, pointsize=16)
        plot(valrange~times, type="n", xlab = xlabel, ylab=ylabel, main = title)
        if (isgrid){
        	abline(v = times, h = bankA, col = "lightgray", lty = "dotted", lwd = 2)
        	abline(v = times, h = bankB, col = "lightgray", lty = "dotted", lwd = 2)
		}
        lines(bankA~times, type=ltype, col="red", lwd=3)
        lines(bankB~times, type=ltype, col="blue", lwd=3)
        legend("topleft", c(legA,legB), lty = c(1,1), lwd = c(3,3), col = c("red", "blue"))
        dev.off()
}

get_single_occurances <- function(dataf){
	npoints <- length(dataf[["IT"]])
	L <- (1:npoints)
	L <- L >= 1
	id_pre <- 0
	it_pre <- 0
	for (i in 1:npoints){
		id <- dataf[["IT"]][i]
		it <- dataf[["ID"]][i]
		if (id == id_pre & it == it_pre){
			L[i] <- FALSE
			}
		id_pre <- id
		it_pre <- it
	}
	return(dataf[L,])
}

get_occurances_distro <- function(niter, itvector){
	nquarters <- niter %/% 60
	quarters <- rep(0, nquarters)
	datalen <- length(itvector)
	acc <- 0
	ind <- 1
	for (i in 1:datalen){
		ind <- itvector[i] %/% 60 + 1
		quarters[ind] = quarters[ind] + 1
	}
	return(quarters)
}

get_aggregate_values <- function(itervector, memoryvector){
	times <- vector()
	aggregates <- vector()
	current_iter <- itervector[1]
	datalength <- length(memoryvector)
	accumulator <- 0
	nvals <- 0
	ind <- 1
	for (i in 1:datalength){
		if (itervector[i] != current_iter){
			aggregates[ind] <- accumulator
			ind <- ind + 1
			accumulator <- 0
			current_iter <- itervector[i]	
		}
		accumulator <- accumulator + memoryvector[i]
	}
	aggregates[ind] <- accumulator
	return(aggregates)
}

get_aggregate_values_v2 <- function(itervector, memoryvector, niter, cycle = 20, phase = 1){
	aggregates <- rep(0, niter)
	current_iter <- itervector[1]
	datalength <- length(memoryvector)
	accumulator <- 0
	nvals <- 0
	for (i in 1:datalength){
		if (itervector[i] != current_iter){
			ind <- (current_iter - phase)/cycle + 1
			aggregates[ind] <- accumulator
			accumulator <- 0
			current_iter <- itervector[i]	
		}
		accumulator <- accumulator + memoryvector[i]
	}
	ind <- (current_iter - phase)/cycle + 1
	aggregates[ind] <- accumulator
	return(aggregates)
}

plot_gdp_to_file_v3 <- function(niter, firmiters, firmvector, cfirmiters, cfirmvector, Rfirmvector, Rcfirmvector, beta = "0.3", cycle = 20, phase = 1){
	times <- (1:niter)
	fsums <- rep(0,niter)
	csums <- rep(0,niter)
	gdp <- rep(0,niter)
	
	Rfsums <- rep(0,niter)
	Rcsums <- rep(0,niter)
	Rgdp <- rep(0,niter)
	
	
	#Regular Firm productions
	current_iter <- firmiters[1]
	datalength <- length(firmvector)
	accumulator <- 0
	Raccumulator <- 0
	for (i in 1:datalength){
		if (firmiters[i] != current_iter){
			ind <- (current_iter - phase)/cycle + 1
			fsums[ind] <- accumulator
			Rfsums[ind] <- Raccumulator
			accumulator <- 0
			Raccumulator <- 0
			current_iter <- firmiters[i]	
		}
		accumulator <- accumulator + firmvector[i]
		Raccumulator <- Raccumulator + Rfirmvector[i]
	}
	ind <- (current_iter - phase)/cycle + 1
	fsums[ind] <- accumulator
	Rfsums[ind] <- Raccumulator

    #constructor Firm productions
	current_iter <- cfirmiters[1]
	datalength <- length(cfirmvector)
	accumulator <- 0
	Raccumulator <- 0
	for (i in 1:datalength){
		if (cfirmiters[i] != current_iter){
			ind <- (current_iter - phase)/cycle + 1
			csums[ind] <- accumulator
			Rcsums[ind] <- Raccumulator
			accumulator <- 0
			Raccumulator <- 0
			current_iter <- cfirmiters[i]	
		}
		accumulator <- accumulator + cfirmvector[i]
		Raccumulator <- Raccumulator + Rcfirmvector[i]
	}
	ind <- (current_iter - phase)/cycle + 1
	csums[ind] <- accumulator
	Rcsums[ind] <- Raccumulator
	
	for (i in 1:niter){
		gdp[i] <- fsums[i] + csums[i]
		Rgdp[i] <- Rfsums[i] + Rcsums[i]
	}
	fname = "aGDP_Monthly.png"
	ylabtext = "GDP - Growth of Housing Units and Consumption Goods Production"
	title = paste("Beta = ", beta, sep = "")
	
	png(fname, width = 1500, height = 800, pointsize=18)
	valrange <- gdp
	valrange[1] <- min(Rgdp)
	plot(valrange~times, type="n", xlab = "Months", ylab=ylabtext, main = title)
	abline(v = times, h = gdp, col = "lightgray", lty = "dotted", lwd = 1)
	abline(v = times, h = Rgdp, col = "lightgray", lty = "dotted", lwd = 1)
	lines(gdp~times, type="o", col = "red", lwd = 3)
	lines(Rgdp~times, type = "o", col = "blue", lwd = 3)
	legend("topleft", c("Nominal","Real"), lty = c(1,1), lwd = c(2,2), col = c("red", "blue"))
	dev.off()
	
	nquarters = niter / 3
	quarters <- (1:nquarters)
	gdpquarters <- rep(0, nquarters)
	Rgdpquarters <- rep(0,nquarters)
	accumulator <- 0
	Raccumulator <- 0
	ind <- 1
	for (i in 1:niter){
		if (i %% 3 == 0){
			accumulator <- accumulator + gdp[i]
			Raccumulator <- Raccumulator + Rgdp[i]
			gdpquarters[ind] <- accumulator
			Rgdpquarters[ind] <- Raccumulator
			ind <- ind + 1
			accumulator <- 0
			Raccumulator <- 0
			}
		else{
			accumulator <- accumulator + gdp[i]
			Raccumulator <- Raccumulator + Rgdp[i]
			}
	}
	fname = "aGDP_Quarterly.png"
	png(fname, width = 1500, height = 800, pointsize=18)
	valrange <- gdpquarters
	valrange[1] <- min(Rgdpquarters)
	plot(valrange~quarters, type="n", xlab = "Quarters", ylab=ylabtext, main = title)
	abline(v = quarters, h = gdpquarters, col = "lightgray", lty = "dotted", lwd = 2)
	abline(v = quarters, h = Rgdpquarters, col = "lightgray", lty = "dotted", lwd = 2)
	lines(gdpquarters~quarters, type="o", col = "red", lwd = 3)
	lines(Rgdpquarters~quarters, type = "o", col = "blue", lwd = 3)
	legend("topleft", c("Nominal","Real"), lty = c(1,1), lwd = c(2,2), col = c("red", "blue"))
	dev.off()
	
	nyears = niter / 12
	years <- (1:nyears)
	gdpyears <- rep(0,nyears)
	accumulator <- 0
	Rgdpyears <- rep(0,nyears)
	Raccumulator <- 0
	ind <- 1
	for (i in 1:niter){
		if (i %% 12 == 0){
			accumulator <- accumulator + gdp[i]
			gdpyears[ind] <- accumulator
			Raccumulator <- Raccumulator + Rgdp[i]
			Rgdpyears[ind] <- Raccumulator
			ind <- ind + 1
			accumulator <- 0
			Raccumulator <- 0
			}
		else{
			accumulator <- accumulator + gdp[i]
			Raccumulator <- Raccumulator + Rgdp[i]
			}
	}
	
	fname = "aGDP_Yearly.png"
	png(fname, width = 1500, height = 800, pointsize=18)
	valrange <- gdpyears
	valrange[1] <- min(Rgdpyears)
	plot(valrange~years, type="n", xlab = "Years", ylab=ylabtext, main = title)
	abline(v = times, h = gdpyears, col = "lightgray", lty = "dotted", lwd = 3)
	abline(v = times, h = Rgdpyears, col = "lightgray", lty = "dotted", lwd = 3)
	lines(gdpyears~years, type="o", col = "red", lwd = 3)
	lines(Rgdpyears~years, type = "o", col = "blue", lwd = 3)
	legend("topleft", c("Nominal","Real"), lty = c(1,1), lwd = c(2,2), col = c("red", "blue"))
	dev.off()
	return(gdpyears)
}
