# Makefile template file for FLAME
#
# FLAME is the FLAME source files
# SOURCE is the user source files
#
# The assumption is that the user only provides C files
# and a model files <file>.xml
#
DEFINES       = -DNONE
LIBMBOARD_DIR = libmboard
LIBMBOARD_INC = $(LIBMBOARD_DIR)/include
LIBMBOARD_LIB = $(LIBMBOARD_DIR)/lib

CC      = gcc
CFLAGS  = -std=c99 -Wall -I$(LIBMBOARD_INC) ${DEFINES}

CFLAGS += -D_DEBUG_MODE -g


LDFLAGS = -L$(LIBMBOARD_LIB)
LIBS    = -lmboard_sd  -lm

#FLAME source files
FLAME   = main.c memory.c xml.c messageboards.c partitioning.c rules.c timing.c

#FLAME auxilary files
AUX 	= stategraph.dot stategraph_colour.dot process_order_graph.dot Doxyfile latex.tex

# FLAME generated model files
SOURCES =  library_functions.c  firm_functions_top.c  household_functions_top.c  bank_functions_top.c  government_functions_top.c  centralbank_functions_top.c  equityfund_functions_top.c  jpoffice_functions_top.c  mall_functions_top.c  reagency_functions_top.c  Market_Consumption/household_functions_consumption.c  Market_Consumption/firm_functions_consumption.c  Market_Consumption/mall_functions_consumption.c  Market_Consumption/centralbank_functions_consumption.c  Market_Labour/household_functions_labour.c  Market_Labour/firm_functions_labour.c  Market_Labour/jpoffice_functions_labour.c  Market_Labour/centralbank_functions_labour.c  Market_Labour/government_functions_labour.c  Market_Labour/equityfund_functions_labour.c  Market_Production/firm_functions_production.c  Market_Credit/firm_functions_credit.c  Market_Credit/household_functions_credit.c  Market_Credit/government_functions_credit.c  Market_Credit/bank_functions_credit.c  Market_Credit/centralbank_functions_credit.c  Market_Credit/equityfund_functions_credit.c  Market_Credit/reagency_functions_credit.c  Market_Housing/firm_functions_housing.c  Market_Housing/household_functions_housing.c  Market_Housing/bank_functions_housing.c  Market_Housing/reagency_functions_housing.c  Market_Housing/centralbank_functions_housing.c 
HEADERS = header.h low_primes.h mboard.h  firm_agent_header.h  household_agent_header.h  equityfund_agent_header.h  bank_agent_header.h  government_agent_header.h  centralbank_agent_header.h  jpoffice_agent_header.h  mall_agent_header.h  reagency_agent_header.h 

DEPS    = Makefile header.h low_primes.h

OBJECTS = $(SOURCES:.c=.o) $(FLAME:.c=.o)
EXECUTABLE = main
RM = rm -f

all: $(SOURCES) $(FLAME) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ $(LIBS)

$(OBJECTS): $(DEPS)

.c.o:
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	$(RM) $(OBJECTS) $(EXECUTABLE) $(EXECUTABLE).exe
vclean:
	$(RM) main $(EXECUTABLE) $(EXECUTABLE).exe $(OBJECTS)  $(FLAME) $(HEADERS)  $(AUX) Makefile
