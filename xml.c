/**
 * \file  xml.c
 * \brief Holds xml reading and writing functions.
 */

#include "header.h"

/** \fn void read_int_static_array(char * buffer, int * j, int ** int_static_array)
 * \brief Reads integer static array.
 */
int read_int_static_array(char * buffer, int /*@unused@*/ buffer_size, int * j, int * int_static_array, int /*@unused@*/ size)
{
	int arraycount = 0;
	int array_k;
	char arraydata[100000];
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '}')
	{
		array_k = 0;
		while(buffer[(*j)] != ',' && buffer[(*j)] != '}')
		{
			if(buffer[(*j)] == '\0') return -1;
			arraydata[array_k] = buffer[(*j)];
			array_k++;
			(*j)++;
		}
		arraydata[array_k] = '\0';
		if (arraycount < size) int_static_array[arraycount] = atoi(arraydata);
		arraycount++;
		if(buffer[(*j)] != '}') (*j)++;
	}

	if (arraycount > size)
	{
				fprintf(stderr, "WARNING: %d 'int' values provided for static array of size %d. Surplus values ignored.\n",
				arraycount, size);
	}
	
	(*j)++;
	return 0;
}

/** \fn void read_float_static_array(char * buffer, int * (*j), int ** float_static_array)
 * \brief Reads float static array.
 */
int read_float_static_array(char * buffer, int /*@unused@*/ buffer_size, int * j, float * float_static_array, int /*@unused@*/ size)
{
	int arraycount = 0;
	int array_k;
	char arraydata[100000];

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '}')
	{
		array_k = 0;
		while(buffer[(*j)] != ',' && buffer[(*j)] != '}')
		{
			if(buffer[(*j)] == '\0') return -1;
			arraydata[array_k] = buffer[(*j)];
			array_k++;
			(*j)++;
		}
		arraydata[array_k] = '\0';
		if (arraycount < size) float_static_array[arraycount] = (float)atof(arraydata);
		arraycount++;
		if(buffer[(*j)] != '}') (*j)++;
	}
	
	if (arraycount > size)
	{
				fprintf(stderr, "WARNING: %d 'float' values provided for static array of size %d. Surplus values ignored.\n",
				arraycount, size);
	}
	
	(*j)++;
	return 0;
}

/** \fn void read_double_static_array(char * buffer, int * (*j), int ** double_static_array)
 * \brief Reads double static array.
 */
int read_double_static_array(char * buffer, int /*@unused@*/ buffer_size, int * j, double * double_static_array, int /*@unused@*/ size)
{
	int arraycount = 0;
	int array_k;
	char arraydata[100000];

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '}')
	{
		array_k = 0;
		while(buffer[(*j)] != ',' && buffer[(*j)] != '}')
		{
			if(buffer[(*j)] == '\0') return -1;
			arraydata[array_k] = buffer[(*j)];
			array_k++;
			(*j)++;
		}
		arraydata[array_k] = '\0';
		if (arraycount < size) double_static_array[arraycount] = atof(arraydata);		
		arraycount++;
		if(buffer[(*j)] != '}') (*j)++;
	}

	if (arraycount > size)
	{
		fprintf(stderr, "WARNING: %d 'double' values provided for static array of size %d. Surplus values ignored.\n",
				arraycount, size);
	}
	
	(*j)++;
	return 0;
}

/** \fn void read_char_static_array(char * buffer, int * (*j), int ** char_static_array)
 * \brief Reads char static array.
 */
int read_char_static_array(char * buffer, int /*@unused@*/ buffer_size, int * j, char * char_static_array, int size)
{
	int arraycount;
	
	while(buffer[(*j)] == ' ')
	{
		(*j)++;
	}
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		char_static_array[arraycount] = buffer[(*j)];
		(*j)++;
	}

	//(*j)++;
	return 0;
}

/** \fn void read_int_dynamic_array(char * buffer, int * (*j), int ** int_dynamic_array)
 * \brief Reads integer dynamic array.
 */
int read_int_dynamic_array(char * buffer, int /*@unused@*/ buffer_size, int * j, int_array * int_dynamic_array)
{
	int arraycount = 0;
	int array_k;
	char arraydata[100000];

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '}')
	{
		array_k = 0;
		while(buffer[(*j)] != ',' && buffer[(*j)] != '}')
		{
			if(buffer[(*j)] == '\0') return -1;
			arraydata[array_k] = buffer[(*j)];
			array_k++;
			(*j)++;
		}
		arraydata[array_k] = '\0';
		add_int(int_dynamic_array, atoi(arraydata));
		arraycount++;
		if(buffer[(*j)] != '}') (*j)++;
	}

	(*j)++;
	return 0;
}

/** \fn void read_float_dynamic_array(char * buffer, int * (*j), int ** float_dynamic_array)
 * \brief Reads float dynamic array.
 */
int read_float_dynamic_array(char * buffer, int /*@unused@*/ buffer_size, int * j, float_array * float_dynamic_array)
{
	int arraycount = 0;
	int array_k;
	char arraydata[100000];

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '}')
	{
		array_k = 0;
		while(buffer[(*j)] != ',' && buffer[(*j)] != '}')
		{
			if(buffer[(*j)] == '\0') return -1;
			arraydata[array_k] = buffer[(*j)];
			array_k++;
			(*j)++;
		}
		arraydata[array_k] = '\0';
		add_float(float_dynamic_array, (float)atof(arraydata));
		arraycount++;
		if(buffer[(*j)] != '}') (*j)++;
	}

	(*j)++;
	return 0;
}

/** \fn void read_double_dynamic_array(char * buffer, int * (*j), int ** double_dynamic_array)
 * \brief Reads double dynamic array.
 */
int read_double_dynamic_array(char * buffer, int /*@unused@*/ buffer_size, int * j, double_array * double_dynamic_array)
{
	int arraycount = 0;
	int array_k;
	char arraydata[100000];

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '}')
	{
		array_k = 0;
		while(buffer[(*j)] != ',' && buffer[(*j)] != '}')
		{
			if(buffer[(*j)] == '\0') return -1;
			arraydata[array_k] = buffer[(*j)];
			array_k++;
			(*j)++;
		}
		arraydata[array_k] = '\0';
		add_double(double_dynamic_array, atof(arraydata));
		arraycount++;
		if(buffer[(*j)] != '}') (*j)++;
	}

	(*j)++;
	return 0;
}

/** \fn void read_char_dynamic_array(char * buffer, int * (*j), int ** char_dynamic_array)
 * \brief Reads char dynamic array.
 */
int read_char_dynamic_array(char * buffer, int /*@unused@*/ buffer_size, int * j, char_array * char_dynamic_array)
{
	if(*j > buffer_size) return -1;
	
	while(buffer[(*j)] == ' ')
	{
		(*j)++;
	}
	
	while(buffer[(*j)] != '\0' && buffer[(*j)] != ',' && buffer[(*j)] != '}')
	{
		add_char(char_dynamic_array, buffer[(*j)]);
		(*j)++;
	}
	
	return 0;
}


/** \fn void read_transaction(char * buffer, int * j, transaction * temp_datatype)
 * \brief Reads transaction datatype.
 */
int read_transaction(char * buffer, int /*@unused@*/ buffer_size, int * j, transaction * temp_datatype)
{
	int array_k;
	char arraydata[100000];
	
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	(*temp_datatype).quantity = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = '\0';
	(*temp_datatype).quantity = atoi(arraydata);
	(*j)++;
	(*temp_datatype).avg_price = 0.0;
	array_k = 0;
	while(buffer[*j] != '}')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = '\0';
	(*temp_datatype).avg_price = atof(arraydata);
	(*j)++;

	return 0;
}

int read_transaction_dynamic_array(char * buffer, int buffer_size, int * j, transaction_array * temp_datatype_array)
{
	int arraycount = 0;
	int rc;
	
	
	

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_transaction(temp_datatype_array, 0, 0.0);
			rc = read_transaction(buffer, buffer_size, j, &(*temp_datatype_array).array[arraycount]);
			if(rc != 0) { printf("Error: reading variable 'transaction' of type '\n"); return -1; }
			arraycount++;
			(*j)++;
		}
		while(buffer[(*j)] != '}' && buffer[(*j)] != '\0' && buffer[(*j)] != '{') { (*j)++; }
	}

	
	
	return 0;
}

int read_transaction_static_array(char * buffer, int buffer_size, int * j, transaction * temp_datatype_array, int size)
{
	int arraycount;
	int rc;

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	for(arraycount = 0; arraycount < size; arraycount++)
	{
		rc = read_transaction(buffer, buffer_size, j, &temp_datatype_array[arraycount]);
		if(rc != 0) { printf("Error: reading variable 'transaction' of type '\n"); return -1; }
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}

	(*j)++;
	return 0;
}

/** \fn void read_buyer(char * buffer, int * j, buyer * temp_datatype)
 * \brief Reads buyer datatype.
 */
int read_buyer(char * buffer, int /*@unused@*/ buffer_size, int * j, buyer * temp_datatype)
{
	int array_k;
	char arraydata[100000];
	
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	(*temp_datatype).id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = '\0';
	(*temp_datatype).id = atoi(arraydata);
	(*j)++;
	(*temp_datatype).budget = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = '\0';
	(*temp_datatype).budget = atof(arraydata);
	(*j)++;
	(*temp_datatype).recieved_quantity = 0;
	array_k = 0;
	while(buffer[*j] != '}')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = '\0';
	(*temp_datatype).recieved_quantity = atoi(arraydata);
	(*j)++;

	return 0;
}

int read_buyer_dynamic_array(char * buffer, int buffer_size, int * j, buyer_array * temp_datatype_array)
{
	int arraycount = 0;
	int rc;
	
	
	
	

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_buyer(temp_datatype_array, 0, 0.0, 0);
			rc = read_buyer(buffer, buffer_size, j, &(*temp_datatype_array).array[arraycount]);
			if(rc != 0) { printf("Error: reading variable 'buyer' of type '\n"); return -1; }
			arraycount++;
			(*j)++;
		}
		while(buffer[(*j)] != '}' && buffer[(*j)] != '\0' && buffer[(*j)] != '{') { (*j)++; }
	}

	
	
	return 0;
}

int read_buyer_static_array(char * buffer, int buffer_size, int * j, buyer * temp_datatype_array, int size)
{
	int arraycount;
	int rc;

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	for(arraycount = 0; arraycount < size; arraycount++)
	{
		rc = read_buyer(buffer, buffer_size, j, &temp_datatype_array[arraycount]);
		if(rc != 0) { printf("Error: reading variable 'buyer' of type '\n"); return -1; }
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}

	(*j)++;
	return 0;
}

/** \fn void read_seller(char * buffer, int * j, seller * temp_datatype)
 * \brief Reads seller datatype.
 */
int read_seller(char * buffer, int /*@unused@*/ buffer_size, int * j, seller * temp_datatype)
{
	int array_k;
	char arraydata[100000];
	
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	(*temp_datatype).id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = '\0';
	(*temp_datatype).id = atoi(arraydata);
	(*j)++;
	(*temp_datatype).price = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = '\0';
	(*temp_datatype).price = atof(arraydata);
	(*j)++;
	(*temp_datatype).inventory = 0;
	array_k = 0;
	while(buffer[*j] != '}')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = '\0';
	(*temp_datatype).inventory = atoi(arraydata);
	(*j)++;

	return 0;
}

int read_seller_dynamic_array(char * buffer, int buffer_size, int * j, seller_array * temp_datatype_array)
{
	int arraycount = 0;
	int rc;
	
	
	
	

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_seller(temp_datatype_array, 0, 0.0, 0);
			rc = read_seller(buffer, buffer_size, j, &(*temp_datatype_array).array[arraycount]);
			if(rc != 0) { printf("Error: reading variable 'seller' of type '\n"); return -1; }
			arraycount++;
			(*j)++;
		}
		while(buffer[(*j)] != '}' && buffer[(*j)] != '\0' && buffer[(*j)] != '{') { (*j)++; }
	}

	
	
	return 0;
}

int read_seller_static_array(char * buffer, int buffer_size, int * j, seller * temp_datatype_array, int size)
{
	int arraycount;
	int rc;

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	for(arraycount = 0; arraycount < size; arraycount++)
	{
		rc = read_seller(buffer, buffer_size, j, &temp_datatype_array[arraycount]);
		if(rc != 0) { printf("Error: reading variable 'seller' of type '\n"); return -1; }
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}

	(*j)++;
	return 0;
}

/** \fn void read_vacancy(char * buffer, int * j, vacancy * temp_datatype)
 * \brief Reads vacancy datatype.
 */
int read_vacancy(char * buffer, int /*@unused@*/ buffer_size, int * j, vacancy * temp_datatype)
{
	int array_k;
	char arraydata[100000];
	
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	(*temp_datatype).id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = '\0';
	(*temp_datatype).id = atoi(arraydata);
	(*j)++;
	(*temp_datatype).wage = 0.0;
	array_k = 0;
	while(buffer[*j] != '}')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = '\0';
	(*temp_datatype).wage = atof(arraydata);
	(*j)++;

	return 0;
}

int read_vacancy_dynamic_array(char * buffer, int buffer_size, int * j, vacancy_array * temp_datatype_array)
{
	int arraycount = 0;
	int rc;
	
	
	

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_vacancy(temp_datatype_array, 0, 0.0);
			rc = read_vacancy(buffer, buffer_size, j, &(*temp_datatype_array).array[arraycount]);
			if(rc != 0) { printf("Error: reading variable 'vacancy' of type '\n"); return -1; }
			arraycount++;
			(*j)++;
		}
		while(buffer[(*j)] != '}' && buffer[(*j)] != '\0' && buffer[(*j)] != '{') { (*j)++; }
	}

	
	
	return 0;
}

int read_vacancy_static_array(char * buffer, int buffer_size, int * j, vacancy * temp_datatype_array, int size)
{
	int arraycount;
	int rc;

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	for(arraycount = 0; arraycount < size; arraycount++)
	{
		rc = read_vacancy(buffer, buffer_size, j, &temp_datatype_array[arraycount]);
		if(rc != 0) { printf("Error: reading variable 'vacancy' of type '\n"); return -1; }
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}

	(*j)++;
	return 0;
}

/** \fn void read_employee(char * buffer, int * j, employee * temp_datatype)
 * \brief Reads employee datatype.
 */
int read_employee(char * buffer, int /*@unused@*/ buffer_size, int * j, employee * temp_datatype)
{
	int array_k;
	char arraydata[100000];
	
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	(*temp_datatype).id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = '\0';
	(*temp_datatype).id = atoi(arraydata);
	(*j)++;
	(*temp_datatype).wage = 0.0;
	array_k = 0;
	while(buffer[*j] != '}')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = '\0';
	(*temp_datatype).wage = atof(arraydata);
	(*j)++;

	return 0;
}

int read_employee_dynamic_array(char * buffer, int buffer_size, int * j, employee_array * temp_datatype_array)
{
	int arraycount = 0;
	int rc;
	
	
	

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_employee(temp_datatype_array, 0, 0.0);
			rc = read_employee(buffer, buffer_size, j, &(*temp_datatype_array).array[arraycount]);
			if(rc != 0) { printf("Error: reading variable 'employee' of type '\n"); return -1; }
			arraycount++;
			(*j)++;
		}
		while(buffer[(*j)] != '}' && buffer[(*j)] != '\0' && buffer[(*j)] != '{') { (*j)++; }
	}

	
	
	return 0;
}

int read_employee_static_array(char * buffer, int buffer_size, int * j, employee * temp_datatype_array, int size)
{
	int arraycount;
	int rc;

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	for(arraycount = 0; arraycount < size; arraycount++)
	{
		rc = read_employee(buffer, buffer_size, j, &temp_datatype_array[arraycount]);
		if(rc != 0) { printf("Error: reading variable 'employee' of type '\n"); return -1; }
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}

	(*j)++;
	return 0;
}

/** \fn void read_mortgage(char * buffer, int * j, mortgage * temp_datatype)
 * \brief Reads mortgage datatype.
 */
int read_mortgage(char * buffer, int /*@unused@*/ buffer_size, int * j, mortgage * temp_datatype)
{
	int array_k;
	char arraydata[100000];
	
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	(*temp_datatype).bank_id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = '\0';
	(*temp_datatype).bank_id = atoi(arraydata);
	(*j)++;
	(*temp_datatype).principal = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = '\0';
	(*temp_datatype).principal = atof(arraydata);
	(*j)++;
	(*temp_datatype).quarters_left = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = '\0';
	(*temp_datatype).quarters_left = atoi(arraydata);
	(*j)++;
	(*temp_datatype).quarterly_interest = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = '\0';
	(*temp_datatype).quarterly_interest = atof(arraydata);
	(*j)++;
	(*temp_datatype).quarterly_principal = 0.0;
	array_k = 0;
	while(buffer[*j] != '}')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = '\0';
	(*temp_datatype).quarterly_principal = atof(arraydata);
	(*j)++;

	return 0;
}

int read_mortgage_dynamic_array(char * buffer, int buffer_size, int * j, mortgage_array * temp_datatype_array)
{
	int arraycount = 0;
	int rc;
	
	
	
	
	
	

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_mortgage(temp_datatype_array, 0, 0.0, 0, 0.0, 0.0);
			rc = read_mortgage(buffer, buffer_size, j, &(*temp_datatype_array).array[arraycount]);
			if(rc != 0) { printf("Error: reading variable 'mortgage' of type '\n"); return -1; }
			arraycount++;
			(*j)++;
		}
		while(buffer[(*j)] != '}' && buffer[(*j)] != '\0' && buffer[(*j)] != '{') { (*j)++; }
	}

	
	
	return 0;
}

int read_mortgage_static_array(char * buffer, int buffer_size, int * j, mortgage * temp_datatype_array, int size)
{
	int arraycount;
	int rc;

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	for(arraycount = 0; arraycount < size; arraycount++)
	{
		rc = read_mortgage(buffer, buffer_size, j, &temp_datatype_array[arraycount]);
		if(rc != 0) { printf("Error: reading variable 'mortgage' of type '\n"); return -1; }
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}

	(*j)++;
	return 0;
}

/** \fn void read_loan(char * buffer, int * j, loan * temp_datatype)
 * \brief Reads loan datatype.
 */
int read_loan(char * buffer, int /*@unused@*/ buffer_size, int * j, loan * temp_datatype)
{
	int array_k;
	char arraydata[100000];
	
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	(*temp_datatype).bank_id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = '\0';
	(*temp_datatype).bank_id = atoi(arraydata);
	(*j)++;
	(*temp_datatype).amount = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = '\0';
	(*temp_datatype).amount = atof(arraydata);
	(*j)++;
	(*temp_datatype).to_be_paid = 0.0;
	array_k = 0;
	while(buffer[*j] != '}')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = '\0';
	(*temp_datatype).to_be_paid = atof(arraydata);
	(*j)++;

	return 0;
}

int read_loan_dynamic_array(char * buffer, int buffer_size, int * j, loan_array * temp_datatype_array)
{
	int arraycount = 0;
	int rc;
	
	
	
	

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_loan(temp_datatype_array, 0, 0.0, 0.0);
			rc = read_loan(buffer, buffer_size, j, &(*temp_datatype_array).array[arraycount]);
			if(rc != 0) { printf("Error: reading variable 'loan' of type '\n"); return -1; }
			arraycount++;
			(*j)++;
		}
		while(buffer[(*j)] != '}' && buffer[(*j)] != '\0' && buffer[(*j)] != '{') { (*j)++; }
	}

	
	
	return 0;
}

int read_loan_static_array(char * buffer, int buffer_size, int * j, loan * temp_datatype_array, int size)
{
	int arraycount;
	int rc;

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	for(arraycount = 0; arraycount < size; arraycount++)
	{
		rc = read_loan(buffer, buffer_size, j, &temp_datatype_array[arraycount]);
		if(rc != 0) { printf("Error: reading variable 'loan' of type '\n"); return -1; }
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}

	(*j)++;
	return 0;
}

/** \fn void read_hbuyer(char * buffer, int * j, hbuyer * temp_datatype)
 * \brief Reads hbuyer datatype.
 */
int read_hbuyer(char * buffer, int /*@unused@*/ buffer_size, int * j, hbuyer * temp_datatype)
{
	int array_k;
	char arraydata[100000];
	
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	(*temp_datatype).buyer_id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = '\0';
	(*temp_datatype).buyer_id = atoi(arraydata);
	(*j)++;
	(*temp_datatype).bank_id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = '\0';
	(*temp_datatype).bank_id = atoi(arraydata);
	(*j)++;
	(*temp_datatype).liquidity = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = '\0';
	(*temp_datatype).liquidity = atof(arraydata);
	(*j)++;
	(*temp_datatype).quarterly_income = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = '\0';
	(*temp_datatype).quarterly_income = atof(arraydata);
	(*j)++;
	(*temp_datatype).quarterly_mortgage_paid = 0.0;
	array_k = 0;
	while(buffer[*j] != '}')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = '\0';
	(*temp_datatype).quarterly_mortgage_paid = atof(arraydata);
	(*j)++;

	return 0;
}

int read_hbuyer_dynamic_array(char * buffer, int buffer_size, int * j, hbuyer_array * temp_datatype_array)
{
	int arraycount = 0;
	int rc;
	
	
	
	
	
	

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_hbuyer(temp_datatype_array, 0, 0, 0.0, 0.0, 0.0);
			rc = read_hbuyer(buffer, buffer_size, j, &(*temp_datatype_array).array[arraycount]);
			if(rc != 0) { printf("Error: reading variable 'hbuyer' of type '\n"); return -1; }
			arraycount++;
			(*j)++;
		}
		while(buffer[(*j)] != '}' && buffer[(*j)] != '\0' && buffer[(*j)] != '{') { (*j)++; }
	}

	
	
	return 0;
}

int read_hbuyer_static_array(char * buffer, int buffer_size, int * j, hbuyer * temp_datatype_array, int size)
{
	int arraycount;
	int rc;

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	for(arraycount = 0; arraycount < size; arraycount++)
	{
		rc = read_hbuyer(buffer, buffer_size, j, &temp_datatype_array[arraycount]);
		if(rc != 0) { printf("Error: reading variable 'hbuyer' of type '\n"); return -1; }
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}

	(*j)++;
	return 0;
}

/** \fn void read_hseller(char * buffer, int * j, hseller * temp_datatype)
 * \brief Reads hseller datatype.
 */
int read_hseller(char * buffer, int /*@unused@*/ buffer_size, int * j, hseller * temp_datatype)
{
	int array_k;
	char arraydata[100000];
	
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	(*temp_datatype).seller_id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = '\0';
	(*temp_datatype).seller_id = atoi(arraydata);
	(*j)++;
	(*temp_datatype).price = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = '\0';
	(*temp_datatype).price = atof(arraydata);
	(*j)++;
	(*temp_datatype).quantity = 0;
	array_k = 0;
	while(buffer[*j] != '}')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = '\0';
	(*temp_datatype).quantity = atoi(arraydata);
	(*j)++;

	return 0;
}

int read_hseller_dynamic_array(char * buffer, int buffer_size, int * j, hseller_array * temp_datatype_array)
{
	int arraycount = 0;
	int rc;
	
	
	
	

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_hseller(temp_datatype_array, 0, 0.0, 0);
			rc = read_hseller(buffer, buffer_size, j, &(*temp_datatype_array).array[arraycount]);
			if(rc != 0) { printf("Error: reading variable 'hseller' of type '\n"); return -1; }
			arraycount++;
			(*j)++;
		}
		while(buffer[(*j)] != '}' && buffer[(*j)] != '\0' && buffer[(*j)] != '{') { (*j)++; }
	}

	
	
	return 0;
}

int read_hseller_static_array(char * buffer, int buffer_size, int * j, hseller * temp_datatype_array, int size)
{
	int arraycount;
	int rc;

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	for(arraycount = 0; arraycount < size; arraycount++)
	{
		rc = read_hseller(buffer, buffer_size, j, &temp_datatype_array[arraycount]);
		if(rc != 0) { printf("Error: reading variable 'hseller' of type '\n"); return -1; }
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}

	(*j)++;
	return 0;
}

/** \fn void read_hbank(char * buffer, int * j, hbank * temp_datatype)
 * \brief Reads hbank datatype.
 */
int read_hbank(char * buffer, int /*@unused@*/ buffer_size, int * j, hbank * temp_datatype)
{
	int array_k;
	char arraydata[100000];
	
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	(*temp_datatype).id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = '\0';
	(*temp_datatype).id = atoi(arraydata);
	(*j)++;
	(*temp_datatype).equity = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = '\0';
	(*temp_datatype).equity = atof(arraydata);
	(*j)++;
	(*temp_datatype).risky_assets = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = '\0';
	(*temp_datatype).risky_assets = atof(arraydata);
	(*j)++;
	(*temp_datatype).amount_mortgaged = 0.0;
	array_k = 0;
	while(buffer[*j] != '}')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = '\0';
	(*temp_datatype).amount_mortgaged = atof(arraydata);
	(*j)++;

	return 0;
}

int read_hbank_dynamic_array(char * buffer, int buffer_size, int * j, hbank_array * temp_datatype_array)
{
	int arraycount = 0;
	int rc;
	
	
	
	
	

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_hbank(temp_datatype_array, 0, 0.0, 0.0, 0.0);
			rc = read_hbank(buffer, buffer_size, j, &(*temp_datatype_array).array[arraycount]);
			if(rc != 0) { printf("Error: reading variable 'hbank' of type '\n"); return -1; }
			arraycount++;
			(*j)++;
		}
		while(buffer[(*j)] != '}' && buffer[(*j)] != '\0' && buffer[(*j)] != '{') { (*j)++; }
	}

	
	
	return 0;
}

int read_hbank_static_array(char * buffer, int buffer_size, int * j, hbank * temp_datatype_array, int size)
{
	int arraycount;
	int rc;

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	for(arraycount = 0; arraycount < size; arraycount++)
	{
		rc = read_hbank(buffer, buffer_size, j, &temp_datatype_array[arraycount]);
		if(rc != 0) { printf("Error: reading variable 'hbank' of type '\n"); return -1; }
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}

	(*j)++;
	return 0;
}



int readEnvironmentXML(char * location)
{
	FILE * file;
	char c = '\0';
	char buffer[100000];
	int index = 0;
	int in_environment = 0;
	int in_ratio_liquidity = 0;
	int in_consumption_adjustment_speed = 0;
	int in_wealth_effect = 0;
	int in_turnover_probability = 0;
	int in_production_markup = 0;
	int in_price_markup = 0;
	int in_firm_memory_persistance = 0;
	int in_ratio_fiscal_policy = 0;
	int in_ratio_capitalist_households = 0;
	int in_inflation_target = 0;
	int in_firms_minimum_equity_ratio = 0;
	int in_firm_startup_leverage = 0;
	int in_household_startup_leverage = 0;
	int in_car_buffer_threshold = 0;
	int in_housing_market_entrance_prob = 0;
	int in_fire_sale_threshold = 0;
	int in_household_budget_constraint = 0;
	int in_capital_adequecy_ratio = 0;
	int in_housing_price_up_rate = 0;
	int in_housing_price_down_rate = 0;
	int in_household_mortgage_writeoff_high = 0;
	int in_household_mortgage_writeoff_low = 0;
	

	buffer[0] = '\0';

	/* Open file */
	if((file = fopen(location, "r"))==NULL)
	{
		printf("Error: cannot open import xml file '%s'\n", location);
		exit(0);
	}
	printf("Reading environment data from: %s\n", location);
	/* Keep reading file until EOF */
	while(c != (char)EOF)
	{
		/* Get the next char from the file */
		c = (char)fgetc(file);
		if(c == '>')
		{
			buffer[index] = '\0';
			if(strcmp(buffer, "environment") == 0) in_environment = 1;
			if(strcmp(buffer, "/environment") == 0) in_environment = 0;
			if(strcmp(buffer, "ratio_liquidity") == 0) in_ratio_liquidity = 1;
			if(strcmp(buffer, "/ratio_liquidity") == 0) in_ratio_liquidity = 0;
			if(strcmp(buffer, "consumption_adjustment_speed") == 0) in_consumption_adjustment_speed = 1;
			if(strcmp(buffer, "/consumption_adjustment_speed") == 0) in_consumption_adjustment_speed = 0;
			if(strcmp(buffer, "wealth_effect") == 0) in_wealth_effect = 1;
			if(strcmp(buffer, "/wealth_effect") == 0) in_wealth_effect = 0;
			if(strcmp(buffer, "turnover_probability") == 0) in_turnover_probability = 1;
			if(strcmp(buffer, "/turnover_probability") == 0) in_turnover_probability = 0;
			if(strcmp(buffer, "production_markup") == 0) in_production_markup = 1;
			if(strcmp(buffer, "/production_markup") == 0) in_production_markup = 0;
			if(strcmp(buffer, "price_markup") == 0) in_price_markup = 1;
			if(strcmp(buffer, "/price_markup") == 0) in_price_markup = 0;
			if(strcmp(buffer, "firm_memory_persistance") == 0) in_firm_memory_persistance = 1;
			if(strcmp(buffer, "/firm_memory_persistance") == 0) in_firm_memory_persistance = 0;
			if(strcmp(buffer, "ratio_fiscal_policy") == 0) in_ratio_fiscal_policy = 1;
			if(strcmp(buffer, "/ratio_fiscal_policy") == 0) in_ratio_fiscal_policy = 0;
			if(strcmp(buffer, "ratio_capitalist_households") == 0) in_ratio_capitalist_households = 1;
			if(strcmp(buffer, "/ratio_capitalist_households") == 0) in_ratio_capitalist_households = 0;
			if(strcmp(buffer, "inflation_target") == 0) in_inflation_target = 1;
			if(strcmp(buffer, "/inflation_target") == 0) in_inflation_target = 0;
			if(strcmp(buffer, "firms_minimum_equity_ratio") == 0) in_firms_minimum_equity_ratio = 1;
			if(strcmp(buffer, "/firms_minimum_equity_ratio") == 0) in_firms_minimum_equity_ratio = 0;
			if(strcmp(buffer, "firm_startup_leverage") == 0) in_firm_startup_leverage = 1;
			if(strcmp(buffer, "/firm_startup_leverage") == 0) in_firm_startup_leverage = 0;
			if(strcmp(buffer, "household_startup_leverage") == 0) in_household_startup_leverage = 1;
			if(strcmp(buffer, "/household_startup_leverage") == 0) in_household_startup_leverage = 0;
			if(strcmp(buffer, "car_buffer_threshold") == 0) in_car_buffer_threshold = 1;
			if(strcmp(buffer, "/car_buffer_threshold") == 0) in_car_buffer_threshold = 0;
			if(strcmp(buffer, "housing_market_entrance_prob") == 0) in_housing_market_entrance_prob = 1;
			if(strcmp(buffer, "/housing_market_entrance_prob") == 0) in_housing_market_entrance_prob = 0;
			if(strcmp(buffer, "fire_sale_threshold") == 0) in_fire_sale_threshold = 1;
			if(strcmp(buffer, "/fire_sale_threshold") == 0) in_fire_sale_threshold = 0;
			if(strcmp(buffer, "household_budget_constraint") == 0) in_household_budget_constraint = 1;
			if(strcmp(buffer, "/household_budget_constraint") == 0) in_household_budget_constraint = 0;
			if(strcmp(buffer, "capital_adequecy_ratio") == 0) in_capital_adequecy_ratio = 1;
			if(strcmp(buffer, "/capital_adequecy_ratio") == 0) in_capital_adequecy_ratio = 0;
			if(strcmp(buffer, "housing_price_up_rate") == 0) in_housing_price_up_rate = 1;
			if(strcmp(buffer, "/housing_price_up_rate") == 0) in_housing_price_up_rate = 0;
			if(strcmp(buffer, "housing_price_down_rate") == 0) in_housing_price_down_rate = 1;
			if(strcmp(buffer, "/housing_price_down_rate") == 0) in_housing_price_down_rate = 0;
			if(strcmp(buffer, "household_mortgage_writeoff_high") == 0) in_household_mortgage_writeoff_high = 1;
			if(strcmp(buffer, "/household_mortgage_writeoff_high") == 0) in_household_mortgage_writeoff_high = 0;
			if(strcmp(buffer, "household_mortgage_writeoff_low") == 0) in_household_mortgage_writeoff_low = 1;
			if(strcmp(buffer, "/household_mortgage_writeoff_low") == 0) in_household_mortgage_writeoff_low = 0;
			
			index = 0;
			buffer[index] = '\0';
		}
		else if(c == '<')
		{
			buffer[index] = '\0';
			if(in_environment == 1)
			{
				if(in_ratio_liquidity == 1) { FLAME_environment_variable_ratio_liquidity = atof(buffer); }
				if(in_consumption_adjustment_speed == 1) { FLAME_environment_variable_consumption_adjustment_speed = atof(buffer); }
				if(in_wealth_effect == 1) { FLAME_environment_variable_wealth_effect = atof(buffer); }
				if(in_turnover_probability == 1) { FLAME_environment_variable_turnover_probability = atof(buffer); }
				if(in_production_markup == 1) { FLAME_environment_variable_production_markup = atof(buffer); }
				if(in_price_markup == 1) { FLAME_environment_variable_price_markup = atof(buffer); }
				if(in_firm_memory_persistance == 1) { FLAME_environment_variable_firm_memory_persistance = atof(buffer); }
				if(in_ratio_fiscal_policy == 1) { FLAME_environment_variable_ratio_fiscal_policy = atof(buffer); }
				if(in_ratio_capitalist_households == 1) { FLAME_environment_variable_ratio_capitalist_households = atof(buffer); }
				if(in_inflation_target == 1) { FLAME_environment_variable_inflation_target = atof(buffer); }
				if(in_firms_minimum_equity_ratio == 1) { FLAME_environment_variable_firms_minimum_equity_ratio = atof(buffer); }
				if(in_firm_startup_leverage == 1) { FLAME_environment_variable_firm_startup_leverage = atof(buffer); }
				if(in_household_startup_leverage == 1) { FLAME_environment_variable_household_startup_leverage = atof(buffer); }
				if(in_car_buffer_threshold == 1) { FLAME_environment_variable_car_buffer_threshold = atof(buffer); }
				if(in_housing_market_entrance_prob == 1) { FLAME_environment_variable_housing_market_entrance_prob = atof(buffer); }
				if(in_fire_sale_threshold == 1) { FLAME_environment_variable_fire_sale_threshold = atof(buffer); }
				if(in_household_budget_constraint == 1) { FLAME_environment_variable_household_budget_constraint = atof(buffer); }
				if(in_capital_adequecy_ratio == 1) { FLAME_environment_variable_capital_adequecy_ratio = atof(buffer); }
				if(in_housing_price_up_rate == 1) { FLAME_environment_variable_housing_price_up_rate = atof(buffer); }
				if(in_housing_price_down_rate == 1) { FLAME_environment_variable_housing_price_down_rate = atof(buffer); }
				if(in_household_mortgage_writeoff_high == 1) { FLAME_environment_variable_household_mortgage_writeoff_high = atof(buffer); }
				if(in_household_mortgage_writeoff_low == 1) { FLAME_environment_variable_household_mortgage_writeoff_low = atof(buffer); }
				
			}
			index = 0;
			buffer[index] = '\0';
		}
		else
		{
			buffer[index] = c;
			if(index < 999) index++;
		}
	}
	/* Close file */
	(void)fclose(file);

	return 0;
}

int readAgentXML(char * location,
				double cloud_data[],
				int partition_method,
				int flag,
				int number_partitions,
				int agent_count,
				int * itno)
{
	FILE * file;
	char c = '\0';
	char buffer[100000];
	char agentname[10000];
	int index = 0;
	int j; /* Index for reading arrays */
	int rc;
	int in_itno = 0;
	int FLAME_in_xagent = 0;
	int FLAME_in_name = 0;
	int in_firm_agent = 0;
	int in_household_agent = 0;
	int in_equityfund_agent = 0;
	int in_bank_agent = 0;
	int in_government_agent = 0;
	int in_centralbank_agent = 0;
	int in_jpoffice_agent = 0;
	int in_mall_agent = 0;
	int in_reagency_agent = 0;
	
	int in_id = 0;
	int in_bank_id = 0;
	int in_isconstructor = 0;
	int in_day_of_month_to_act = 0;
	int in_isinsolvent = 0;
	int in_it_no = 0;
	int in_day_of_week_to_act = 0;
	int in_average_goods_price = 0;
	int in_employees = 0;
	int in_wage_offer = 0;
	int in_average_wage = 0;
	int in_no_employees = 0;
	int in_vacancies = 0;
	int in_employees_needed = 0;
	int in_day_of_month_wages_paid = 0;
	int in_labour_productivity = 0;
	int in_production_current = 0;
	int in_expected_sales = 0;
	int in_production_plan = 0;
	int in_unit_goods_price = 0;
	int in_unit_cost = 0;
	int in_day_of_month_production_completed = 0;
	int in_unit_house_price = 0;
	int in_labour_productivity_construction = 0;
	int in_capital_productivity_construction = 0;
	int in_capital_construction = 0;
	int in_physical_capital = 0;
	int in_projects = 0;
	int in_loans_interest_rate = 0;
	int in_debt = 0;
	int in_inventory = 0;
	int in_sales = 0;
	int in_revenues = 0;
	int in_total_assets = 0;
	int in_operating_costs = 0;
	int in_labour_costs = 0;
	int in_total_interest_payments = 0;
	int in_dividends_paid = 0;
	int in_dividends_to_be_paid = 0;
	int in_retained_earnings = 0;
	int in_net_earnings = 0;
	int in_ebit = 0;
	int in_equity = 0;
	int in_liquidity = 0;
	int in_capital_goods = 0;
	int in_capital_goods_price = 0;
	int in_hasloan = 0;
	int in_hasinvestment = 0;
	int in_planned_investment_costs = 0;
	int in_liquidity_need = 0;
	int in_loan_list = 0;
	int in_labour_tax_rate = 0;
	int in_delta_housing_price = 0;
	int in_weekly_consumption_budget = 0;
	int in_planned_consumption_budget = 0;
	int in_my_employer_id = 0;
	int in_wage = 0;
	int in_day_of_month_wage_recieved = 0;
	int in_mortgages_interest_rate = 0;
	int in_mortgages_list = 0;
	int in_mortgages = 0;
	int in_housing_payment = 0;
	int in_housing_price = 0;
	int in_housing_units = 0;
	int in_n_shares = 0;
	int in_capital_income = 0;
	int in_previous_wages = 0;
	int in_labour_income = 0;
	int in_housing_value = 0;
	int in_delta_housing_value = 0;
	int in_hmarket_role = 0;
	int in_equity_ratio = 0;
	int in_minimum_equity_ratio = 0;
	int in_mortgage_costs = 0;
	int in_share_firms = 0;
	int in_share_construction_firms = 0;
	int in_share_banks = 0;
	int in_dividends_recieved = 0;
	int in_dividends_retained = 0;
	int in_firm_investment = 0;
	int in_capital_tax_rate = 0;
	int in_loans = 0;
	int in_deposits = 0;
	int in_centralbank_debt = 0;
	int in_total_writeoffs = 0;
	int in_interest_rate = 0;
	int in_interests_accrued = 0;
	int in_interests_paid = 0;
	int in_total_dividends = 0;
	int in_total_costs = 0;
	int in_unemployment_rate = 0;
	int in_population_size = 0;
	int in_labour_tax_income = 0;
	int in_capital_tax_income = 0;
	int in_gov_general_benefit_rate = 0;
	int in_gov_unemployment_rate = 0;
	int in_general_benefits = 0;
	int in_unemployment_benefits = 0;
	int in_earnings = 0;
	int in_centralbank_income = 0;
	int in_expenditures = 0;
	int in_consumption_goods_prices = 0;
	int in_goods = 0;
	int in_weekly_price_averages = 0;
	int in_loans_banks = 0;
	int in_loans_government = 0;
	int in_fiat_money = 0;
	int in_liquidity_banks = 0;
	int in_liquidity_government = 0;
	int in_houses = 0;
	int in_goods_transactions = 0;
	int in_housing_transactions = 0;
	
	xmachine_memory_firm * current_firm_agent = NULL;
	xmachine_memory_household * current_household_agent = NULL;
	xmachine_memory_equityfund * current_equityfund_agent = NULL;
	xmachine_memory_bank * current_bank_agent = NULL;
	xmachine_memory_government * current_government_agent = NULL;
	xmachine_memory_centralbank * current_centralbank_agent = NULL;
	xmachine_memory_jpoffice * current_jpoffice_agent = NULL;
	xmachine_memory_mall * current_mall_agent = NULL;
	xmachine_memory_reagency * current_reagency_agent = NULL;
	
	/* Things for round-robin partitioning */
	int geometric = 1;
	int other = 2;
	double posx=0.0, posy=0.0, posz=0.0;

	j = 0;
	rc = 0;
	
	/* Use j and rc to stop compiler warnings if not used */
	if(j == 0 && rc == 0) {}
	
	agentname[0] = '\0';
	buffer[0] = '\0';

	/* Open file */
	if((file = fopen(location, "r"))==NULL)
	{
		printf("Error: cannot open import xml file '%s'\n", location);
		exit(0);
	}
	printf("Reading agent data from: %s\n", location);
	/* Keep reading file until EOF */
	while(c != (char)EOF)
	{
		/* Get the next char from the file */
		c = (char)fgetc(file);
		if(c == '>')
		{
			buffer[index] = '\0';
			if(strcmp(buffer, "itno") == 0) in_itno = 1;
			if(strcmp(buffer, "/itno") == 0) in_itno = 0;
			if(strcmp(buffer, "xagent") == 0)
			{
				FLAME_in_xagent = 1;
				agentname[0] = '\0';
			}
			if(strcmp(buffer, "/xagent") == 0)
			{	
				if(strcmp(agentname, "firm") == 0)
				{
					if(current_firm_agent == NULL) { printf("Memory error reading firm agent\n"); exit(0); }
					
					posx = (double)0.0;
					posy = (double)0.0;
					posz = (double)0.0;
					
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						/* Next line should be commented out? */
						add_firm_agent_internal(current_firm_agent, firm_start_state);

						/* Update the cloud data */
						if ( posx < cloud_data[0] ) cloud_data[0] = posx;
						if ( posx > cloud_data[1] ) cloud_data[1] = posx;
						if ( posy < cloud_data[2] ) cloud_data[2] = posy;
						if ( posy > cloud_data[3] ) cloud_data[3] = posy;
						if ( posz < cloud_data[2] ) cloud_data[4] = posz;
						if ( posz > cloud_data[3] ) cloud_data[5] = posz;
					}
					else
					{
						if(partition_method == geometric)
						{
							if (
								((current_node->partition_data[0] == SPINF) || (current_node->partition_data[0] != SPINF && posx >= current_node->partition_data[0])) &&
								((current_node->partition_data[1] == SPINF) || (current_node->partition_data[1] != SPINF && posx < current_node->partition_data[1])) &&
								((current_node->partition_data[2] == SPINF) || (current_node->partition_data[2] != SPINF && posy >= current_node->partition_data[2])) &&
								((current_node->partition_data[3] == SPINF) || (current_node->partition_data[3] != SPINF && posy < current_node->partition_data[3])) &&
								((current_node->partition_data[4] == SPINF) || (current_node->partition_data[4] != SPINF && posz >= current_node->partition_data[4])) &&
								((current_node->partition_data[5] == SPINF) || (current_node->partition_data[5] != SPINF && posz < current_node->partition_data[5]))
							)
							{
								add_firm_agent_internal(current_firm_agent, firm_start_state);
							}
						}
						else if (partition_method == other)
						{
							if (agent_count % number_partitions == 0)
							{
								add_firm_agent_internal(current_firm_agent, firm_start_state);
							}
							++agent_count;
						}
					}
				}
				else if(strcmp(agentname, "household") == 0)
				{
					if(current_household_agent == NULL) { printf("Memory error reading household agent\n"); exit(0); }
					
					posx = (double)0.0;
					posy = (double)0.0;
					posz = (double)0.0;
					
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						/* Next line should be commented out? */
						add_household_agent_internal(current_household_agent, household_start_state);

						/* Update the cloud data */
						if ( posx < cloud_data[0] ) cloud_data[0] = posx;
						if ( posx > cloud_data[1] ) cloud_data[1] = posx;
						if ( posy < cloud_data[2] ) cloud_data[2] = posy;
						if ( posy > cloud_data[3] ) cloud_data[3] = posy;
						if ( posz < cloud_data[2] ) cloud_data[4] = posz;
						if ( posz > cloud_data[3] ) cloud_data[5] = posz;
					}
					else
					{
						if(partition_method == geometric)
						{
							if (
								((current_node->partition_data[0] == SPINF) || (current_node->partition_data[0] != SPINF && posx >= current_node->partition_data[0])) &&
								((current_node->partition_data[1] == SPINF) || (current_node->partition_data[1] != SPINF && posx < current_node->partition_data[1])) &&
								((current_node->partition_data[2] == SPINF) || (current_node->partition_data[2] != SPINF && posy >= current_node->partition_data[2])) &&
								((current_node->partition_data[3] == SPINF) || (current_node->partition_data[3] != SPINF && posy < current_node->partition_data[3])) &&
								((current_node->partition_data[4] == SPINF) || (current_node->partition_data[4] != SPINF && posz >= current_node->partition_data[4])) &&
								((current_node->partition_data[5] == SPINF) || (current_node->partition_data[5] != SPINF && posz < current_node->partition_data[5]))
							)
							{
								add_household_agent_internal(current_household_agent, household_start_state);
							}
						}
						else if (partition_method == other)
						{
							if (agent_count % number_partitions == 0)
							{
								add_household_agent_internal(current_household_agent, household_start_state);
							}
							++agent_count;
						}
					}
				}
				else if(strcmp(agentname, "equityfund") == 0)
				{
					if(current_equityfund_agent == NULL) { printf("Memory error reading equityfund agent\n"); exit(0); }
					
					posx = (double)0.0;
					posy = (double)0.0;
					posz = (double)0.0;
					
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						/* Next line should be commented out? */
						add_equityfund_agent_internal(current_equityfund_agent, equityfund_start_state);

						/* Update the cloud data */
						if ( posx < cloud_data[0] ) cloud_data[0] = posx;
						if ( posx > cloud_data[1] ) cloud_data[1] = posx;
						if ( posy < cloud_data[2] ) cloud_data[2] = posy;
						if ( posy > cloud_data[3] ) cloud_data[3] = posy;
						if ( posz < cloud_data[2] ) cloud_data[4] = posz;
						if ( posz > cloud_data[3] ) cloud_data[5] = posz;
					}
					else
					{
						if(partition_method == geometric)
						{
							if (
								((current_node->partition_data[0] == SPINF) || (current_node->partition_data[0] != SPINF && posx >= current_node->partition_data[0])) &&
								((current_node->partition_data[1] == SPINF) || (current_node->partition_data[1] != SPINF && posx < current_node->partition_data[1])) &&
								((current_node->partition_data[2] == SPINF) || (current_node->partition_data[2] != SPINF && posy >= current_node->partition_data[2])) &&
								((current_node->partition_data[3] == SPINF) || (current_node->partition_data[3] != SPINF && posy < current_node->partition_data[3])) &&
								((current_node->partition_data[4] == SPINF) || (current_node->partition_data[4] != SPINF && posz >= current_node->partition_data[4])) &&
								((current_node->partition_data[5] == SPINF) || (current_node->partition_data[5] != SPINF && posz < current_node->partition_data[5]))
							)
							{
								add_equityfund_agent_internal(current_equityfund_agent, equityfund_start_state);
							}
						}
						else if (partition_method == other)
						{
							if (agent_count % number_partitions == 0)
							{
								add_equityfund_agent_internal(current_equityfund_agent, equityfund_start_state);
							}
							++agent_count;
						}
					}
				}
				else if(strcmp(agentname, "bank") == 0)
				{
					if(current_bank_agent == NULL) { printf("Memory error reading bank agent\n"); exit(0); }
					
					posx = (double)0.0;
					posy = (double)0.0;
					posz = (double)0.0;
					
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						/* Next line should be commented out? */
						add_bank_agent_internal(current_bank_agent, bank_start_state);

						/* Update the cloud data */
						if ( posx < cloud_data[0] ) cloud_data[0] = posx;
						if ( posx > cloud_data[1] ) cloud_data[1] = posx;
						if ( posy < cloud_data[2] ) cloud_data[2] = posy;
						if ( posy > cloud_data[3] ) cloud_data[3] = posy;
						if ( posz < cloud_data[2] ) cloud_data[4] = posz;
						if ( posz > cloud_data[3] ) cloud_data[5] = posz;
					}
					else
					{
						if(partition_method == geometric)
						{
							if (
								((current_node->partition_data[0] == SPINF) || (current_node->partition_data[0] != SPINF && posx >= current_node->partition_data[0])) &&
								((current_node->partition_data[1] == SPINF) || (current_node->partition_data[1] != SPINF && posx < current_node->partition_data[1])) &&
								((current_node->partition_data[2] == SPINF) || (current_node->partition_data[2] != SPINF && posy >= current_node->partition_data[2])) &&
								((current_node->partition_data[3] == SPINF) || (current_node->partition_data[3] != SPINF && posy < current_node->partition_data[3])) &&
								((current_node->partition_data[4] == SPINF) || (current_node->partition_data[4] != SPINF && posz >= current_node->partition_data[4])) &&
								((current_node->partition_data[5] == SPINF) || (current_node->partition_data[5] != SPINF && posz < current_node->partition_data[5]))
							)
							{
								add_bank_agent_internal(current_bank_agent, bank_start_state);
							}
						}
						else if (partition_method == other)
						{
							if (agent_count % number_partitions == 0)
							{
								add_bank_agent_internal(current_bank_agent, bank_start_state);
							}
							++agent_count;
						}
					}
				}
				else if(strcmp(agentname, "government") == 0)
				{
					if(current_government_agent == NULL) { printf("Memory error reading government agent\n"); exit(0); }
					
					posx = (double)0.0;
					posy = (double)0.0;
					posz = (double)0.0;
					
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						/* Next line should be commented out? */
						add_government_agent_internal(current_government_agent, government_start_state);

						/* Update the cloud data */
						if ( posx < cloud_data[0] ) cloud_data[0] = posx;
						if ( posx > cloud_data[1] ) cloud_data[1] = posx;
						if ( posy < cloud_data[2] ) cloud_data[2] = posy;
						if ( posy > cloud_data[3] ) cloud_data[3] = posy;
						if ( posz < cloud_data[2] ) cloud_data[4] = posz;
						if ( posz > cloud_data[3] ) cloud_data[5] = posz;
					}
					else
					{
						if(partition_method == geometric)
						{
							if (
								((current_node->partition_data[0] == SPINF) || (current_node->partition_data[0] != SPINF && posx >= current_node->partition_data[0])) &&
								((current_node->partition_data[1] == SPINF) || (current_node->partition_data[1] != SPINF && posx < current_node->partition_data[1])) &&
								((current_node->partition_data[2] == SPINF) || (current_node->partition_data[2] != SPINF && posy >= current_node->partition_data[2])) &&
								((current_node->partition_data[3] == SPINF) || (current_node->partition_data[3] != SPINF && posy < current_node->partition_data[3])) &&
								((current_node->partition_data[4] == SPINF) || (current_node->partition_data[4] != SPINF && posz >= current_node->partition_data[4])) &&
								((current_node->partition_data[5] == SPINF) || (current_node->partition_data[5] != SPINF && posz < current_node->partition_data[5]))
							)
							{
								add_government_agent_internal(current_government_agent, government_start_state);
							}
						}
						else if (partition_method == other)
						{
							if (agent_count % number_partitions == 0)
							{
								add_government_agent_internal(current_government_agent, government_start_state);
							}
							++agent_count;
						}
					}
				}
				else if(strcmp(agentname, "centralbank") == 0)
				{
					if(current_centralbank_agent == NULL) { printf("Memory error reading centralbank agent\n"); exit(0); }
					
					posx = (double)0.0;
					posy = (double)0.0;
					posz = (double)0.0;
					
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						/* Next line should be commented out? */
						add_centralbank_agent_internal(current_centralbank_agent, centralbank_start_state);

						/* Update the cloud data */
						if ( posx < cloud_data[0] ) cloud_data[0] = posx;
						if ( posx > cloud_data[1] ) cloud_data[1] = posx;
						if ( posy < cloud_data[2] ) cloud_data[2] = posy;
						if ( posy > cloud_data[3] ) cloud_data[3] = posy;
						if ( posz < cloud_data[2] ) cloud_data[4] = posz;
						if ( posz > cloud_data[3] ) cloud_data[5] = posz;
					}
					else
					{
						if(partition_method == geometric)
						{
							if (
								((current_node->partition_data[0] == SPINF) || (current_node->partition_data[0] != SPINF && posx >= current_node->partition_data[0])) &&
								((current_node->partition_data[1] == SPINF) || (current_node->partition_data[1] != SPINF && posx < current_node->partition_data[1])) &&
								((current_node->partition_data[2] == SPINF) || (current_node->partition_data[2] != SPINF && posy >= current_node->partition_data[2])) &&
								((current_node->partition_data[3] == SPINF) || (current_node->partition_data[3] != SPINF && posy < current_node->partition_data[3])) &&
								((current_node->partition_data[4] == SPINF) || (current_node->partition_data[4] != SPINF && posz >= current_node->partition_data[4])) &&
								((current_node->partition_data[5] == SPINF) || (current_node->partition_data[5] != SPINF && posz < current_node->partition_data[5]))
							)
							{
								add_centralbank_agent_internal(current_centralbank_agent, centralbank_start_state);
							}
						}
						else if (partition_method == other)
						{
							if (agent_count % number_partitions == 0)
							{
								add_centralbank_agent_internal(current_centralbank_agent, centralbank_start_state);
							}
							++agent_count;
						}
					}
				}
				else if(strcmp(agentname, "jpoffice") == 0)
				{
					if(current_jpoffice_agent == NULL) { printf("Memory error reading jpoffice agent\n"); exit(0); }
					
					posx = (double)0.0;
					posy = (double)0.0;
					posz = (double)0.0;
					
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						/* Next line should be commented out? */
						add_jpoffice_agent_internal(current_jpoffice_agent, jpoffice_start_state);

						/* Update the cloud data */
						if ( posx < cloud_data[0] ) cloud_data[0] = posx;
						if ( posx > cloud_data[1] ) cloud_data[1] = posx;
						if ( posy < cloud_data[2] ) cloud_data[2] = posy;
						if ( posy > cloud_data[3] ) cloud_data[3] = posy;
						if ( posz < cloud_data[2] ) cloud_data[4] = posz;
						if ( posz > cloud_data[3] ) cloud_data[5] = posz;
					}
					else
					{
						if(partition_method == geometric)
						{
							if (
								((current_node->partition_data[0] == SPINF) || (current_node->partition_data[0] != SPINF && posx >= current_node->partition_data[0])) &&
								((current_node->partition_data[1] == SPINF) || (current_node->partition_data[1] != SPINF && posx < current_node->partition_data[1])) &&
								((current_node->partition_data[2] == SPINF) || (current_node->partition_data[2] != SPINF && posy >= current_node->partition_data[2])) &&
								((current_node->partition_data[3] == SPINF) || (current_node->partition_data[3] != SPINF && posy < current_node->partition_data[3])) &&
								((current_node->partition_data[4] == SPINF) || (current_node->partition_data[4] != SPINF && posz >= current_node->partition_data[4])) &&
								((current_node->partition_data[5] == SPINF) || (current_node->partition_data[5] != SPINF && posz < current_node->partition_data[5]))
							)
							{
								add_jpoffice_agent_internal(current_jpoffice_agent, jpoffice_start_state);
							}
						}
						else if (partition_method == other)
						{
							if (agent_count % number_partitions == 0)
							{
								add_jpoffice_agent_internal(current_jpoffice_agent, jpoffice_start_state);
							}
							++agent_count;
						}
					}
				}
				else if(strcmp(agentname, "mall") == 0)
				{
					if(current_mall_agent == NULL) { printf("Memory error reading mall agent\n"); exit(0); }
					
					posx = (double)0.0;
					posy = (double)0.0;
					posz = (double)0.0;
					
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						/* Next line should be commented out? */
						add_mall_agent_internal(current_mall_agent, mall_start_state);

						/* Update the cloud data */
						if ( posx < cloud_data[0] ) cloud_data[0] = posx;
						if ( posx > cloud_data[1] ) cloud_data[1] = posx;
						if ( posy < cloud_data[2] ) cloud_data[2] = posy;
						if ( posy > cloud_data[3] ) cloud_data[3] = posy;
						if ( posz < cloud_data[2] ) cloud_data[4] = posz;
						if ( posz > cloud_data[3] ) cloud_data[5] = posz;
					}
					else
					{
						if(partition_method == geometric)
						{
							if (
								((current_node->partition_data[0] == SPINF) || (current_node->partition_data[0] != SPINF && posx >= current_node->partition_data[0])) &&
								((current_node->partition_data[1] == SPINF) || (current_node->partition_data[1] != SPINF && posx < current_node->partition_data[1])) &&
								((current_node->partition_data[2] == SPINF) || (current_node->partition_data[2] != SPINF && posy >= current_node->partition_data[2])) &&
								((current_node->partition_data[3] == SPINF) || (current_node->partition_data[3] != SPINF && posy < current_node->partition_data[3])) &&
								((current_node->partition_data[4] == SPINF) || (current_node->partition_data[4] != SPINF && posz >= current_node->partition_data[4])) &&
								((current_node->partition_data[5] == SPINF) || (current_node->partition_data[5] != SPINF && posz < current_node->partition_data[5]))
							)
							{
								add_mall_agent_internal(current_mall_agent, mall_start_state);
							}
						}
						else if (partition_method == other)
						{
							if (agent_count % number_partitions == 0)
							{
								add_mall_agent_internal(current_mall_agent, mall_start_state);
							}
							++agent_count;
						}
					}
				}
				else if(strcmp(agentname, "reagency") == 0)
				{
					if(current_reagency_agent == NULL) { printf("Memory error reading reagency agent\n"); exit(0); }
					
					posx = (double)0.0;
					posy = (double)0.0;
					posz = (double)0.0;
					
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						/* Next line should be commented out? */
						add_reagency_agent_internal(current_reagency_agent, reagency_start_state);

						/* Update the cloud data */
						if ( posx < cloud_data[0] ) cloud_data[0] = posx;
						if ( posx > cloud_data[1] ) cloud_data[1] = posx;
						if ( posy < cloud_data[2] ) cloud_data[2] = posy;
						if ( posy > cloud_data[3] ) cloud_data[3] = posy;
						if ( posz < cloud_data[2] ) cloud_data[4] = posz;
						if ( posz > cloud_data[3] ) cloud_data[5] = posz;
					}
					else
					{
						if(partition_method == geometric)
						{
							if (
								((current_node->partition_data[0] == SPINF) || (current_node->partition_data[0] != SPINF && posx >= current_node->partition_data[0])) &&
								((current_node->partition_data[1] == SPINF) || (current_node->partition_data[1] != SPINF && posx < current_node->partition_data[1])) &&
								((current_node->partition_data[2] == SPINF) || (current_node->partition_data[2] != SPINF && posy >= current_node->partition_data[2])) &&
								((current_node->partition_data[3] == SPINF) || (current_node->partition_data[3] != SPINF && posy < current_node->partition_data[3])) &&
								((current_node->partition_data[4] == SPINF) || (current_node->partition_data[4] != SPINF && posz >= current_node->partition_data[4])) &&
								((current_node->partition_data[5] == SPINF) || (current_node->partition_data[5] != SPINF && posz < current_node->partition_data[5]))
							)
							{
								add_reagency_agent_internal(current_reagency_agent, reagency_start_state);
							}
						}
						else if (partition_method == other)
						{
							if (agent_count % number_partitions == 0)
							{
								add_reagency_agent_internal(current_reagency_agent, reagency_start_state);
							}
							++agent_count;
						}
					}
				}
				else
				{
					printf("Warning: agent name undefined - '%s'\n", agentname);
					exit(0);
				}
				agentname[0] = '\0';
				FLAME_in_xagent = 0;
				in_firm_agent = 0;
				in_household_agent = 0;
				in_equityfund_agent = 0;
				in_bank_agent = 0;
				in_government_agent = 0;
				in_centralbank_agent = 0;
				in_jpoffice_agent = 0;
				in_mall_agent = 0;
				in_reagency_agent = 0;
				
			}
			if(strcmp(buffer, "name") == 0) FLAME_in_name = 1;
			if(strcmp(buffer, "/name") == 0) FLAME_in_name = 0;
			if(strcmp(buffer, "id") == 0) { in_id = 1; }
			if(strcmp(buffer, "/id") == 0) { in_id = 0; }
			if(strcmp(buffer, "bank_id") == 0) { in_bank_id = 1; }
			if(strcmp(buffer, "/bank_id") == 0) { in_bank_id = 0; }
			if(strcmp(buffer, "isconstructor") == 0) { in_isconstructor = 1; }
			if(strcmp(buffer, "/isconstructor") == 0) { in_isconstructor = 0; }
			if(strcmp(buffer, "day_of_month_to_act") == 0) { in_day_of_month_to_act = 1; }
			if(strcmp(buffer, "/day_of_month_to_act") == 0) { in_day_of_month_to_act = 0; }
			if(strcmp(buffer, "isinsolvent") == 0) { in_isinsolvent = 1; }
			if(strcmp(buffer, "/isinsolvent") == 0) { in_isinsolvent = 0; }
			if(strcmp(buffer, "it_no") == 0) { in_it_no = 1; }
			if(strcmp(buffer, "/it_no") == 0) { in_it_no = 0; }
			if(strcmp(buffer, "day_of_week_to_act") == 0) { in_day_of_week_to_act = 1; }
			if(strcmp(buffer, "/day_of_week_to_act") == 0) { in_day_of_week_to_act = 0; }
			if(strcmp(buffer, "average_goods_price") == 0) { in_average_goods_price = 1; }
			if(strcmp(buffer, "/average_goods_price") == 0) { in_average_goods_price = 0; }
			if(strcmp(buffer, "employees") == 0) { in_employees = 1; }
			if(strcmp(buffer, "/employees") == 0) { in_employees = 0; }
			if(strcmp(buffer, "wage_offer") == 0) { in_wage_offer = 1; }
			if(strcmp(buffer, "/wage_offer") == 0) { in_wage_offer = 0; }
			if(strcmp(buffer, "average_wage") == 0) { in_average_wage = 1; }
			if(strcmp(buffer, "/average_wage") == 0) { in_average_wage = 0; }
			if(strcmp(buffer, "no_employees") == 0) { in_no_employees = 1; }
			if(strcmp(buffer, "/no_employees") == 0) { in_no_employees = 0; }
			if(strcmp(buffer, "vacancies") == 0) { in_vacancies = 1; }
			if(strcmp(buffer, "/vacancies") == 0) { in_vacancies = 0; }
			if(strcmp(buffer, "employees_needed") == 0) { in_employees_needed = 1; }
			if(strcmp(buffer, "/employees_needed") == 0) { in_employees_needed = 0; }
			if(strcmp(buffer, "day_of_month_wages_paid") == 0) { in_day_of_month_wages_paid = 1; }
			if(strcmp(buffer, "/day_of_month_wages_paid") == 0) { in_day_of_month_wages_paid = 0; }
			if(strcmp(buffer, "labour_productivity") == 0) { in_labour_productivity = 1; }
			if(strcmp(buffer, "/labour_productivity") == 0) { in_labour_productivity = 0; }
			if(strcmp(buffer, "production_current") == 0) { in_production_current = 1; }
			if(strcmp(buffer, "/production_current") == 0) { in_production_current = 0; }
			if(strcmp(buffer, "expected_sales") == 0) { in_expected_sales = 1; }
			if(strcmp(buffer, "/expected_sales") == 0) { in_expected_sales = 0; }
			if(strcmp(buffer, "production_plan") == 0) { in_production_plan = 1; }
			if(strcmp(buffer, "/production_plan") == 0) { in_production_plan = 0; }
			if(strcmp(buffer, "unit_goods_price") == 0) { in_unit_goods_price = 1; }
			if(strcmp(buffer, "/unit_goods_price") == 0) { in_unit_goods_price = 0; }
			if(strcmp(buffer, "unit_cost") == 0) { in_unit_cost = 1; }
			if(strcmp(buffer, "/unit_cost") == 0) { in_unit_cost = 0; }
			if(strcmp(buffer, "day_of_month_production_completed") == 0) { in_day_of_month_production_completed = 1; }
			if(strcmp(buffer, "/day_of_month_production_completed") == 0) { in_day_of_month_production_completed = 0; }
			if(strcmp(buffer, "unit_house_price") == 0) { in_unit_house_price = 1; }
			if(strcmp(buffer, "/unit_house_price") == 0) { in_unit_house_price = 0; }
			if(strcmp(buffer, "labour_productivity_construction") == 0) { in_labour_productivity_construction = 1; }
			if(strcmp(buffer, "/labour_productivity_construction") == 0) { in_labour_productivity_construction = 0; }
			if(strcmp(buffer, "capital_productivity_construction") == 0) { in_capital_productivity_construction = 1; }
			if(strcmp(buffer, "/capital_productivity_construction") == 0) { in_capital_productivity_construction = 0; }
			if(strcmp(buffer, "capital_construction") == 0) { in_capital_construction = 1; }
			if(strcmp(buffer, "/capital_construction") == 0) { in_capital_construction = 0; }
			if(strcmp(buffer, "physical_capital") == 0) { in_physical_capital = 1; }
			if(strcmp(buffer, "/physical_capital") == 0) { in_physical_capital = 0; }
			if(strcmp(buffer, "projects") == 0) { in_projects = 1; }
			if(strcmp(buffer, "/projects") == 0) { in_projects = 0; }
			if(strcmp(buffer, "loans_interest_rate") == 0) { in_loans_interest_rate = 1; }
			if(strcmp(buffer, "/loans_interest_rate") == 0) { in_loans_interest_rate = 0; }
			if(strcmp(buffer, "debt") == 0) { in_debt = 1; }
			if(strcmp(buffer, "/debt") == 0) { in_debt = 0; }
			if(strcmp(buffer, "inventory") == 0) { in_inventory = 1; }
			if(strcmp(buffer, "/inventory") == 0) { in_inventory = 0; }
			if(strcmp(buffer, "sales") == 0) { in_sales = 1; }
			if(strcmp(buffer, "/sales") == 0) { in_sales = 0; }
			if(strcmp(buffer, "revenues") == 0) { in_revenues = 1; }
			if(strcmp(buffer, "/revenues") == 0) { in_revenues = 0; }
			if(strcmp(buffer, "total_assets") == 0) { in_total_assets = 1; }
			if(strcmp(buffer, "/total_assets") == 0) { in_total_assets = 0; }
			if(strcmp(buffer, "operating_costs") == 0) { in_operating_costs = 1; }
			if(strcmp(buffer, "/operating_costs") == 0) { in_operating_costs = 0; }
			if(strcmp(buffer, "labour_costs") == 0) { in_labour_costs = 1; }
			if(strcmp(buffer, "/labour_costs") == 0) { in_labour_costs = 0; }
			if(strcmp(buffer, "total_interest_payments") == 0) { in_total_interest_payments = 1; }
			if(strcmp(buffer, "/total_interest_payments") == 0) { in_total_interest_payments = 0; }
			if(strcmp(buffer, "dividends_paid") == 0) { in_dividends_paid = 1; }
			if(strcmp(buffer, "/dividends_paid") == 0) { in_dividends_paid = 0; }
			if(strcmp(buffer, "dividends_to_be_paid") == 0) { in_dividends_to_be_paid = 1; }
			if(strcmp(buffer, "/dividends_to_be_paid") == 0) { in_dividends_to_be_paid = 0; }
			if(strcmp(buffer, "retained_earnings") == 0) { in_retained_earnings = 1; }
			if(strcmp(buffer, "/retained_earnings") == 0) { in_retained_earnings = 0; }
			if(strcmp(buffer, "net_earnings") == 0) { in_net_earnings = 1; }
			if(strcmp(buffer, "/net_earnings") == 0) { in_net_earnings = 0; }
			if(strcmp(buffer, "ebit") == 0) { in_ebit = 1; }
			if(strcmp(buffer, "/ebit") == 0) { in_ebit = 0; }
			if(strcmp(buffer, "equity") == 0) { in_equity = 1; }
			if(strcmp(buffer, "/equity") == 0) { in_equity = 0; }
			if(strcmp(buffer, "liquidity") == 0) { in_liquidity = 1; }
			if(strcmp(buffer, "/liquidity") == 0) { in_liquidity = 0; }
			if(strcmp(buffer, "capital_goods") == 0) { in_capital_goods = 1; }
			if(strcmp(buffer, "/capital_goods") == 0) { in_capital_goods = 0; }
			if(strcmp(buffer, "capital_goods_price") == 0) { in_capital_goods_price = 1; }
			if(strcmp(buffer, "/capital_goods_price") == 0) { in_capital_goods_price = 0; }
			if(strcmp(buffer, "hasloan") == 0) { in_hasloan = 1; }
			if(strcmp(buffer, "/hasloan") == 0) { in_hasloan = 0; }
			if(strcmp(buffer, "hasinvestment") == 0) { in_hasinvestment = 1; }
			if(strcmp(buffer, "/hasinvestment") == 0) { in_hasinvestment = 0; }
			if(strcmp(buffer, "planned_investment_costs") == 0) { in_planned_investment_costs = 1; }
			if(strcmp(buffer, "/planned_investment_costs") == 0) { in_planned_investment_costs = 0; }
			if(strcmp(buffer, "liquidity_need") == 0) { in_liquidity_need = 1; }
			if(strcmp(buffer, "/liquidity_need") == 0) { in_liquidity_need = 0; }
			if(strcmp(buffer, "loan_list") == 0) { in_loan_list = 1; }
			if(strcmp(buffer, "/loan_list") == 0) { in_loan_list = 0; }
			if(strcmp(buffer, "labour_tax_rate") == 0) { in_labour_tax_rate = 1; }
			if(strcmp(buffer, "/labour_tax_rate") == 0) { in_labour_tax_rate = 0; }
			if(strcmp(buffer, "delta_housing_price") == 0) { in_delta_housing_price = 1; }
			if(strcmp(buffer, "/delta_housing_price") == 0) { in_delta_housing_price = 0; }
			if(strcmp(buffer, "weekly_consumption_budget") == 0) { in_weekly_consumption_budget = 1; }
			if(strcmp(buffer, "/weekly_consumption_budget") == 0) { in_weekly_consumption_budget = 0; }
			if(strcmp(buffer, "planned_consumption_budget") == 0) { in_planned_consumption_budget = 1; }
			if(strcmp(buffer, "/planned_consumption_budget") == 0) { in_planned_consumption_budget = 0; }
			if(strcmp(buffer, "my_employer_id") == 0) { in_my_employer_id = 1; }
			if(strcmp(buffer, "/my_employer_id") == 0) { in_my_employer_id = 0; }
			if(strcmp(buffer, "wage") == 0) { in_wage = 1; }
			if(strcmp(buffer, "/wage") == 0) { in_wage = 0; }
			if(strcmp(buffer, "day_of_month_wage_recieved") == 0) { in_day_of_month_wage_recieved = 1; }
			if(strcmp(buffer, "/day_of_month_wage_recieved") == 0) { in_day_of_month_wage_recieved = 0; }
			if(strcmp(buffer, "mortgages_interest_rate") == 0) { in_mortgages_interest_rate = 1; }
			if(strcmp(buffer, "/mortgages_interest_rate") == 0) { in_mortgages_interest_rate = 0; }
			if(strcmp(buffer, "mortgages_list") == 0) { in_mortgages_list = 1; }
			if(strcmp(buffer, "/mortgages_list") == 0) { in_mortgages_list = 0; }
			if(strcmp(buffer, "mortgages") == 0) { in_mortgages = 1; }
			if(strcmp(buffer, "/mortgages") == 0) { in_mortgages = 0; }
			if(strcmp(buffer, "housing_payment") == 0) { in_housing_payment = 1; }
			if(strcmp(buffer, "/housing_payment") == 0) { in_housing_payment = 0; }
			if(strcmp(buffer, "housing_price") == 0) { in_housing_price = 1; }
			if(strcmp(buffer, "/housing_price") == 0) { in_housing_price = 0; }
			if(strcmp(buffer, "housing_units") == 0) { in_housing_units = 1; }
			if(strcmp(buffer, "/housing_units") == 0) { in_housing_units = 0; }
			if(strcmp(buffer, "n_shares") == 0) { in_n_shares = 1; }
			if(strcmp(buffer, "/n_shares") == 0) { in_n_shares = 0; }
			if(strcmp(buffer, "capital_income") == 0) { in_capital_income = 1; }
			if(strcmp(buffer, "/capital_income") == 0) { in_capital_income = 0; }
			if(strcmp(buffer, "previous_wages") == 0) { in_previous_wages = 1; }
			if(strcmp(buffer, "/previous_wages") == 0) { in_previous_wages = 0; }
			if(strcmp(buffer, "labour_income") == 0) { in_labour_income = 1; }
			if(strcmp(buffer, "/labour_income") == 0) { in_labour_income = 0; }
			if(strcmp(buffer, "housing_value") == 0) { in_housing_value = 1; }
			if(strcmp(buffer, "/housing_value") == 0) { in_housing_value = 0; }
			if(strcmp(buffer, "delta_housing_value") == 0) { in_delta_housing_value = 1; }
			if(strcmp(buffer, "/delta_housing_value") == 0) { in_delta_housing_value = 0; }
			if(strcmp(buffer, "hmarket_role") == 0) { in_hmarket_role = 1; }
			if(strcmp(buffer, "/hmarket_role") == 0) { in_hmarket_role = 0; }
			if(strcmp(buffer, "equity_ratio") == 0) { in_equity_ratio = 1; }
			if(strcmp(buffer, "/equity_ratio") == 0) { in_equity_ratio = 0; }
			if(strcmp(buffer, "minimum_equity_ratio") == 0) { in_minimum_equity_ratio = 1; }
			if(strcmp(buffer, "/minimum_equity_ratio") == 0) { in_minimum_equity_ratio = 0; }
			if(strcmp(buffer, "mortgage_costs") == 0) { in_mortgage_costs = 1; }
			if(strcmp(buffer, "/mortgage_costs") == 0) { in_mortgage_costs = 0; }
			if(strcmp(buffer, "share_firms") == 0) { in_share_firms = 1; }
			if(strcmp(buffer, "/share_firms") == 0) { in_share_firms = 0; }
			if(strcmp(buffer, "share_construction_firms") == 0) { in_share_construction_firms = 1; }
			if(strcmp(buffer, "/share_construction_firms") == 0) { in_share_construction_firms = 0; }
			if(strcmp(buffer, "share_banks") == 0) { in_share_banks = 1; }
			if(strcmp(buffer, "/share_banks") == 0) { in_share_banks = 0; }
			if(strcmp(buffer, "dividends_recieved") == 0) { in_dividends_recieved = 1; }
			if(strcmp(buffer, "/dividends_recieved") == 0) { in_dividends_recieved = 0; }
			if(strcmp(buffer, "dividends_retained") == 0) { in_dividends_retained = 1; }
			if(strcmp(buffer, "/dividends_retained") == 0) { in_dividends_retained = 0; }
			if(strcmp(buffer, "firm_investment") == 0) { in_firm_investment = 1; }
			if(strcmp(buffer, "/firm_investment") == 0) { in_firm_investment = 0; }
			if(strcmp(buffer, "capital_tax_rate") == 0) { in_capital_tax_rate = 1; }
			if(strcmp(buffer, "/capital_tax_rate") == 0) { in_capital_tax_rate = 0; }
			if(strcmp(buffer, "loans") == 0) { in_loans = 1; }
			if(strcmp(buffer, "/loans") == 0) { in_loans = 0; }
			if(strcmp(buffer, "deposits") == 0) { in_deposits = 1; }
			if(strcmp(buffer, "/deposits") == 0) { in_deposits = 0; }
			if(strcmp(buffer, "centralbank_debt") == 0) { in_centralbank_debt = 1; }
			if(strcmp(buffer, "/centralbank_debt") == 0) { in_centralbank_debt = 0; }
			if(strcmp(buffer, "total_writeoffs") == 0) { in_total_writeoffs = 1; }
			if(strcmp(buffer, "/total_writeoffs") == 0) { in_total_writeoffs = 0; }
			if(strcmp(buffer, "interest_rate") == 0) { in_interest_rate = 1; }
			if(strcmp(buffer, "/interest_rate") == 0) { in_interest_rate = 0; }
			if(strcmp(buffer, "interests_accrued") == 0) { in_interests_accrued = 1; }
			if(strcmp(buffer, "/interests_accrued") == 0) { in_interests_accrued = 0; }
			if(strcmp(buffer, "interests_paid") == 0) { in_interests_paid = 1; }
			if(strcmp(buffer, "/interests_paid") == 0) { in_interests_paid = 0; }
			if(strcmp(buffer, "total_dividends") == 0) { in_total_dividends = 1; }
			if(strcmp(buffer, "/total_dividends") == 0) { in_total_dividends = 0; }
			if(strcmp(buffer, "total_costs") == 0) { in_total_costs = 1; }
			if(strcmp(buffer, "/total_costs") == 0) { in_total_costs = 0; }
			if(strcmp(buffer, "unemployment_rate") == 0) { in_unemployment_rate = 1; }
			if(strcmp(buffer, "/unemployment_rate") == 0) { in_unemployment_rate = 0; }
			if(strcmp(buffer, "population_size") == 0) { in_population_size = 1; }
			if(strcmp(buffer, "/population_size") == 0) { in_population_size = 0; }
			if(strcmp(buffer, "labour_tax_income") == 0) { in_labour_tax_income = 1; }
			if(strcmp(buffer, "/labour_tax_income") == 0) { in_labour_tax_income = 0; }
			if(strcmp(buffer, "capital_tax_income") == 0) { in_capital_tax_income = 1; }
			if(strcmp(buffer, "/capital_tax_income") == 0) { in_capital_tax_income = 0; }
			if(strcmp(buffer, "gov_general_benefit_rate") == 0) { in_gov_general_benefit_rate = 1; }
			if(strcmp(buffer, "/gov_general_benefit_rate") == 0) { in_gov_general_benefit_rate = 0; }
			if(strcmp(buffer, "gov_unemployment_rate") == 0) { in_gov_unemployment_rate = 1; }
			if(strcmp(buffer, "/gov_unemployment_rate") == 0) { in_gov_unemployment_rate = 0; }
			if(strcmp(buffer, "general_benefits") == 0) { in_general_benefits = 1; }
			if(strcmp(buffer, "/general_benefits") == 0) { in_general_benefits = 0; }
			if(strcmp(buffer, "unemployment_benefits") == 0) { in_unemployment_benefits = 1; }
			if(strcmp(buffer, "/unemployment_benefits") == 0) { in_unemployment_benefits = 0; }
			if(strcmp(buffer, "earnings") == 0) { in_earnings = 1; }
			if(strcmp(buffer, "/earnings") == 0) { in_earnings = 0; }
			if(strcmp(buffer, "centralbank_income") == 0) { in_centralbank_income = 1; }
			if(strcmp(buffer, "/centralbank_income") == 0) { in_centralbank_income = 0; }
			if(strcmp(buffer, "expenditures") == 0) { in_expenditures = 1; }
			if(strcmp(buffer, "/expenditures") == 0) { in_expenditures = 0; }
			if(strcmp(buffer, "consumption_goods_prices") == 0) { in_consumption_goods_prices = 1; }
			if(strcmp(buffer, "/consumption_goods_prices") == 0) { in_consumption_goods_prices = 0; }
			if(strcmp(buffer, "goods") == 0) { in_goods = 1; }
			if(strcmp(buffer, "/goods") == 0) { in_goods = 0; }
			if(strcmp(buffer, "weekly_price_averages") == 0) { in_weekly_price_averages = 1; }
			if(strcmp(buffer, "/weekly_price_averages") == 0) { in_weekly_price_averages = 0; }
			if(strcmp(buffer, "loans_banks") == 0) { in_loans_banks = 1; }
			if(strcmp(buffer, "/loans_banks") == 0) { in_loans_banks = 0; }
			if(strcmp(buffer, "loans_government") == 0) { in_loans_government = 1; }
			if(strcmp(buffer, "/loans_government") == 0) { in_loans_government = 0; }
			if(strcmp(buffer, "fiat_money") == 0) { in_fiat_money = 1; }
			if(strcmp(buffer, "/fiat_money") == 0) { in_fiat_money = 0; }
			if(strcmp(buffer, "liquidity_banks") == 0) { in_liquidity_banks = 1; }
			if(strcmp(buffer, "/liquidity_banks") == 0) { in_liquidity_banks = 0; }
			if(strcmp(buffer, "liquidity_government") == 0) { in_liquidity_government = 1; }
			if(strcmp(buffer, "/liquidity_government") == 0) { in_liquidity_government = 0; }
			if(strcmp(buffer, "houses") == 0) { in_houses = 1; }
			if(strcmp(buffer, "/houses") == 0) { in_houses = 0; }
			if(strcmp(buffer, "goods_transactions") == 0) { in_goods_transactions = 1; }
			if(strcmp(buffer, "/goods_transactions") == 0) { in_goods_transactions = 0; }
			if(strcmp(buffer, "housing_transactions") == 0) { in_housing_transactions = 1; }
			if(strcmp(buffer, "/housing_transactions") == 0) { in_housing_transactions = 0; }
			
			index = 0;
			buffer[index] = '\0';
		}
		else if(c == '<')
		{
			buffer[index] = '\0';
			
			if(in_itno && FLAME_in_xagent == 0) *itno = atoi(buffer);
			if(FLAME_in_xagent == 1)
			{
				if(FLAME_in_name == 1)
				{
					strcpy(agentname, buffer);

					if(strcmp(agentname, "firm") == 0)
					{
						current_firm_agent = init_firm_agent();
						in_firm_agent = 1;
					}
					else if(strcmp(agentname, "household") == 0)
					{
						current_household_agent = init_household_agent();
						in_household_agent = 1;
					}
					else if(strcmp(agentname, "equityfund") == 0)
					{
						current_equityfund_agent = init_equityfund_agent();
						in_equityfund_agent = 1;
					}
					else if(strcmp(agentname, "bank") == 0)
					{
						current_bank_agent = init_bank_agent();
						in_bank_agent = 1;
					}
					else if(strcmp(agentname, "government") == 0)
					{
						current_government_agent = init_government_agent();
						in_government_agent = 1;
					}
					else if(strcmp(agentname, "centralbank") == 0)
					{
						current_centralbank_agent = init_centralbank_agent();
						in_centralbank_agent = 1;
					}
					else if(strcmp(agentname, "jpoffice") == 0)
					{
						current_jpoffice_agent = init_jpoffice_agent();
						in_jpoffice_agent = 1;
					}
					else if(strcmp(agentname, "mall") == 0)
					{
						current_mall_agent = init_mall_agent();
						in_mall_agent = 1;
					}
					else if(strcmp(agentname, "reagency") == 0)
					{
						current_reagency_agent = init_reagency_agent();
						in_reagency_agent = 1;
					}
					else
					{
						printf("Warning: agent name undefined - '%s'\n", agentname);
						exit(0);
					}
				}
				else if(in_firm_agent == 1)
				{
					if(in_id) { current_firm_agent->id = atoi(buffer); }
					if(in_bank_id) { current_firm_agent->bank_id = atoi(buffer); }
					if(in_isconstructor) { current_firm_agent->isconstructor = atoi(buffer); }
					if(in_day_of_month_to_act) { current_firm_agent->day_of_month_to_act = atoi(buffer); }
					if(in_isinsolvent) { current_firm_agent->isinsolvent = atoi(buffer); }
					if(in_it_no) { current_firm_agent->it_no = atoi(buffer); }
					if(in_day_of_week_to_act) { current_firm_agent->day_of_week_to_act = atoi(buffer); }
					if(in_average_goods_price) { current_firm_agent->average_goods_price = atof(buffer); }
					if(in_employees) { j = 0;
						rc = read_int_dynamic_array(buffer, index, &j, &current_firm_agent->employees);
						if(rc != 0) { printf("Error: reading 'firm' agent variable 'employees' of type 'int_array'\n"); exit(0); } }
					if(in_wage_offer) { current_firm_agent->wage_offer = atof(buffer); }
					if(in_average_wage) { current_firm_agent->average_wage = atof(buffer); }
					if(in_no_employees) { current_firm_agent->no_employees = atoi(buffer); }
					if(in_vacancies) { current_firm_agent->vacancies = atoi(buffer); }
					if(in_employees_needed) { current_firm_agent->employees_needed = atoi(buffer); }
					if(in_day_of_month_wages_paid) { current_firm_agent->day_of_month_wages_paid = atoi(buffer); }
					if(in_labour_productivity) { current_firm_agent->labour_productivity = atof(buffer); }
					if(in_production_current) { current_firm_agent->production_current = atoi(buffer); }
					if(in_expected_sales) { current_firm_agent->expected_sales = atoi(buffer); }
					if(in_production_plan) { current_firm_agent->production_plan = atoi(buffer); }
					if(in_unit_goods_price) { current_firm_agent->unit_goods_price = atof(buffer); }
					if(in_unit_cost) { current_firm_agent->unit_cost = atof(buffer); }
					if(in_day_of_month_production_completed) { current_firm_agent->day_of_month_production_completed = atoi(buffer); }
					if(in_unit_house_price) { current_firm_agent->unit_house_price = atof(buffer); }
					if(in_labour_productivity_construction) { current_firm_agent->labour_productivity_construction = atof(buffer); }
					if(in_capital_productivity_construction) { current_firm_agent->capital_productivity_construction = atof(buffer); }
					if(in_capital_construction) { current_firm_agent->capital_construction = atof(buffer); }
					if(in_physical_capital) { current_firm_agent->physical_capital = atof(buffer); }
					if(in_projects) { j = 0;
						rc = read_int_static_array(buffer, index, &j, current_firm_agent->projects, 12);
						if(rc != 0) { printf("Error: reading 'firm' agent variable 'projects' of type 'int'\n"); exit(0); } }
					if(in_loans_interest_rate) { current_firm_agent->loans_interest_rate = atof(buffer); }
					if(in_debt) { current_firm_agent->debt = atof(buffer); }
					if(in_inventory) { current_firm_agent->inventory = atoi(buffer); }
					if(in_sales) { current_firm_agent->sales = atoi(buffer); }
					if(in_revenues) { current_firm_agent->revenues = atof(buffer); }
					if(in_total_assets) { current_firm_agent->total_assets = atof(buffer); }
					if(in_operating_costs) { current_firm_agent->operating_costs = atof(buffer); }
					if(in_labour_costs) { current_firm_agent->labour_costs = atof(buffer); }
					if(in_total_interest_payments) { current_firm_agent->total_interest_payments = atof(buffer); }
					if(in_dividends_paid) { current_firm_agent->dividends_paid = atof(buffer); }
					if(in_dividends_to_be_paid) { current_firm_agent->dividends_to_be_paid = atof(buffer); }
					if(in_retained_earnings) { current_firm_agent->retained_earnings = atof(buffer); }
					if(in_net_earnings) { current_firm_agent->net_earnings = atof(buffer); }
					if(in_ebit) { current_firm_agent->ebit = atof(buffer); }
					if(in_equity) { current_firm_agent->equity = atof(buffer); }
					if(in_liquidity) { current_firm_agent->liquidity = atof(buffer); }
					if(in_capital_goods) { current_firm_agent->capital_goods = atof(buffer); }
					if(in_capital_goods_price) { current_firm_agent->capital_goods_price = atof(buffer); }
					if(in_hasloan) { current_firm_agent->hasloan = atoi(buffer); }
					if(in_hasinvestment) { current_firm_agent->hasinvestment = atoi(buffer); }
					if(in_planned_investment_costs) { current_firm_agent->planned_investment_costs = atof(buffer); }
					if(in_liquidity_need) { current_firm_agent->liquidity_need = atof(buffer); }
					if(in_loan_list) { j = 0;
						rc = read_loan_static_array(buffer, index, &j, current_firm_agent->loan_list, 2);
						if(rc != 0) { printf("Error: reading 'firm' agent variable 'loan_list' of type 'loan'\n"); exit(0); } }
					if(in_labour_tax_rate) { current_firm_agent->labour_tax_rate = atof(buffer); }
					if(in_delta_housing_price) { current_firm_agent->delta_housing_price = atof(buffer); }
				 }else if(in_household_agent == 1)
				{
					if(in_id) { current_household_agent->id = atoi(buffer); }
					if(in_bank_id) { current_household_agent->bank_id = atoi(buffer); }
					if(in_it_no) { current_household_agent->it_no = atoi(buffer); }
					if(in_day_of_week_to_act) { current_household_agent->day_of_week_to_act = atoi(buffer); }
					if(in_weekly_consumption_budget) { current_household_agent->weekly_consumption_budget = atof(buffer); }
					if(in_planned_consumption_budget) { current_household_agent->planned_consumption_budget = atof(buffer); }
					if(in_my_employer_id) { current_household_agent->my_employer_id = atoi(buffer); }
					if(in_wage) { current_household_agent->wage = atof(buffer); }
					if(in_day_of_month_to_act) { current_household_agent->day_of_month_to_act = atoi(buffer); }
					if(in_day_of_month_wage_recieved) { current_household_agent->day_of_month_wage_recieved = atoi(buffer); }
					if(in_mortgages_interest_rate) { current_household_agent->mortgages_interest_rate = atof(buffer); }
					if(in_labour_tax_rate) { current_household_agent->labour_tax_rate = atof(buffer); }
					if(in_mortgages_list) { j = 0;
						rc = read_mortgage_dynamic_array(buffer, index, &j, &current_household_agent->mortgages_list);
						if(rc != 0) { printf("Error: reading 'household' agent variable 'mortgages_list' of type 'mortgage_array'\n"); exit(0); } }
					if(in_mortgages) { current_household_agent->mortgages = atof(buffer); }
					if(in_housing_payment) { current_household_agent->housing_payment = atof(buffer); }
					if(in_equity) { current_household_agent->equity = atof(buffer); }
					if(in_housing_price) { current_household_agent->housing_price = atof(buffer); }
					if(in_housing_units) { current_household_agent->housing_units = atoi(buffer); }
					if(in_n_shares) { current_household_agent->n_shares = atoi(buffer); }
					if(in_liquidity) { current_household_agent->liquidity = atof(buffer); }
					if(in_capital_income) { current_household_agent->capital_income = atof(buffer); }
					if(in_previous_wages) { j = 0;
						rc = read_int_static_array(buffer, index, &j, current_household_agent->previous_wages, 3);
						if(rc != 0) { printf("Error: reading 'household' agent variable 'previous_wages' of type 'int'\n"); exit(0); } }
					if(in_labour_income) { current_household_agent->labour_income = atof(buffer); }
					if(in_total_assets) { current_household_agent->total_assets = atof(buffer); }
					if(in_housing_value) { current_household_agent->housing_value = atof(buffer); }
					if(in_delta_housing_value) { current_household_agent->delta_housing_value = atof(buffer); }
					if(in_hmarket_role) { current_household_agent->hmarket_role = atoi(buffer); }
					if(in_equity_ratio) { current_household_agent->equity_ratio = atof(buffer); }
					if(in_minimum_equity_ratio) { current_household_agent->minimum_equity_ratio = atof(buffer); }
					if(in_mortgage_costs) { j = 0;
						rc = read_double_static_array(buffer, index, &j, current_household_agent->mortgage_costs, 3);
						if(rc != 0) { printf("Error: reading 'household' agent variable 'mortgage_costs' of type 'double'\n"); exit(0); } }
				 }else if(in_equityfund_agent == 1)
				{
					if(in_id) { current_equityfund_agent->id = atoi(buffer); }
					if(in_it_no) { current_equityfund_agent->it_no = atoi(buffer); }
					if(in_day_of_month_to_act) { current_equityfund_agent->day_of_month_to_act = atoi(buffer); }
					if(in_share_firms) { current_equityfund_agent->share_firms = atof(buffer); }
					if(in_share_construction_firms) { current_equityfund_agent->share_construction_firms = atof(buffer); }
					if(in_share_banks) { current_equityfund_agent->share_banks = atof(buffer); }
					if(in_equity) { current_equityfund_agent->equity = atof(buffer); }
					if(in_liquidity) { current_equityfund_agent->liquidity = atof(buffer); }
					if(in_n_shares) { current_equityfund_agent->n_shares = atoi(buffer); }
					if(in_dividends_recieved) { current_equityfund_agent->dividends_recieved = atof(buffer); }
					if(in_dividends_retained) { current_equityfund_agent->dividends_retained = atof(buffer); }
					if(in_dividends_paid) { current_equityfund_agent->dividends_paid = atof(buffer); }
					if(in_firm_investment) { current_equityfund_agent->firm_investment = atof(buffer); }
					if(in_capital_tax_rate) { current_equityfund_agent->capital_tax_rate = atof(buffer); }
				 }else if(in_bank_agent == 1)
				{
					if(in_id) { current_bank_agent->id = atoi(buffer); }
					if(in_day_of_month_to_act) { current_bank_agent->day_of_month_to_act = atoi(buffer); }
					if(in_day_of_week_to_act) { current_bank_agent->day_of_week_to_act = atoi(buffer); }
					if(in_it_no) { current_bank_agent->it_no = atoi(buffer); }
					if(in_total_assets) { current_bank_agent->total_assets = atof(buffer); }
					if(in_loans) { current_bank_agent->loans = atof(buffer); }
					if(in_mortgages) { current_bank_agent->mortgages = atof(buffer); }
					if(in_deposits) { current_bank_agent->deposits = atof(buffer); }
					if(in_centralbank_debt) { current_bank_agent->centralbank_debt = atof(buffer); }
					if(in_equity) { current_bank_agent->equity = atof(buffer); }
					if(in_liquidity) { current_bank_agent->liquidity = atof(buffer); }
					if(in_revenues) { current_bank_agent->revenues = atof(buffer); }
					if(in_total_writeoffs) { current_bank_agent->total_writeoffs = atof(buffer); }
					if(in_interest_rate) { current_bank_agent->interest_rate = atof(buffer); }
					if(in_interests_accrued) { current_bank_agent->interests_accrued = atof(buffer); }
					if(in_interests_paid) { current_bank_agent->interests_paid = atof(buffer); }
					if(in_dividends_paid) { current_bank_agent->dividends_paid = atof(buffer); }
					if(in_total_dividends) { current_bank_agent->total_dividends = atof(buffer); }
					if(in_retained_earnings) { current_bank_agent->retained_earnings = atof(buffer); }
					if(in_net_earnings) { current_bank_agent->net_earnings = atof(buffer); }
					if(in_total_costs) { current_bank_agent->total_costs = atof(buffer); }
				 }else if(in_government_agent == 1)
				{
					if(in_id) { current_government_agent->id = atoi(buffer); }
					if(in_it_no) { current_government_agent->it_no = atoi(buffer); }
					if(in_average_wage) { current_government_agent->average_wage = atof(buffer); }
					if(in_unemployment_rate) { current_government_agent->unemployment_rate = atof(buffer); }
					if(in_population_size) { current_government_agent->population_size = atoi(buffer); }
					if(in_debt) { current_government_agent->debt = atof(buffer); }
					if(in_equity) { current_government_agent->equity = atof(buffer); }
					if(in_liquidity) { current_government_agent->liquidity = atof(buffer); }
					if(in_day_of_month_to_act) { current_government_agent->day_of_month_to_act = atoi(buffer); }
					if(in_day_of_month_wages_paid) { current_government_agent->day_of_month_wages_paid = atoi(buffer); }
					if(in_capital_tax_rate) { current_government_agent->capital_tax_rate = atof(buffer); }
					if(in_labour_tax_rate) { current_government_agent->labour_tax_rate = atof(buffer); }
					if(in_labour_tax_income) { current_government_agent->labour_tax_income = atof(buffer); }
					if(in_capital_tax_income) { current_government_agent->capital_tax_income = atof(buffer); }
					if(in_gov_general_benefit_rate) { current_government_agent->gov_general_benefit_rate = atof(buffer); }
					if(in_gov_unemployment_rate) { current_government_agent->gov_unemployment_rate = atof(buffer); }
					if(in_general_benefits) { current_government_agent->general_benefits = atof(buffer); }
					if(in_unemployment_benefits) { current_government_agent->unemployment_benefits = atof(buffer); }
					if(in_earnings) { current_government_agent->earnings = atof(buffer); }
					if(in_centralbank_income) { current_government_agent->centralbank_income = atof(buffer); }
					if(in_expenditures) { current_government_agent->expenditures = atof(buffer); }
				 }else if(in_centralbank_agent == 1)
				{
					if(in_id) { current_centralbank_agent->id = atoi(buffer); }
					if(in_day_of_month_to_act) { current_centralbank_agent->day_of_month_to_act = atoi(buffer); }
					if(in_unemployment_rate) { current_centralbank_agent->unemployment_rate = atof(buffer); }
					if(in_consumption_goods_prices) { j = 0;
						rc = read_double_static_array(buffer, index, &j, current_centralbank_agent->consumption_goods_prices, 12);
						if(rc != 0) { printf("Error: reading 'centralbank' agent variable 'consumption_goods_prices' of type 'double'\n"); exit(0); } }
					if(in_it_no) { current_centralbank_agent->it_no = atoi(buffer); }
					if(in_day_of_week_to_act) { current_centralbank_agent->day_of_week_to_act = atoi(buffer); }
					if(in_goods) { j = 0;
						rc = read_transaction(buffer, index, &j, &current_centralbank_agent->goods);
						if(rc != 0) { printf("Error: reading 'centralbank' agent variable 'goods' of type 'transaction'\n"); exit(0); } }
					if(in_weekly_price_averages) { j = 0;
						rc = read_double_static_array(buffer, index, &j, current_centralbank_agent->weekly_price_averages, 4);
						if(rc != 0) { printf("Error: reading 'centralbank' agent variable 'weekly_price_averages' of type 'double'\n"); exit(0); } }
					if(in_interest_rate) { current_centralbank_agent->interest_rate = atof(buffer); }
					if(in_liquidity) { current_centralbank_agent->liquidity = atof(buffer); }
					if(in_loans_banks) { current_centralbank_agent->loans_banks = atof(buffer); }
					if(in_loans_government) { current_centralbank_agent->loans_government = atof(buffer); }
					if(in_fiat_money) { current_centralbank_agent->fiat_money = atof(buffer); }
					if(in_equity) { current_centralbank_agent->equity = atof(buffer); }
					if(in_liquidity_banks) { current_centralbank_agent->liquidity_banks = atof(buffer); }
					if(in_liquidity_government) { current_centralbank_agent->liquidity_government = atof(buffer); }
					if(in_total_assets) { current_centralbank_agent->total_assets = atof(buffer); }
					if(in_total_writeoffs) { current_centralbank_agent->total_writeoffs = atof(buffer); }
					if(in_interests_accrued) { current_centralbank_agent->interests_accrued = atof(buffer); }
					if(in_revenues) { current_centralbank_agent->revenues = atof(buffer); }
					if(in_net_earnings) { current_centralbank_agent->net_earnings = atof(buffer); }
					if(in_total_costs) { current_centralbank_agent->total_costs = atof(buffer); }
					if(in_houses) { j = 0;
						rc = read_transaction(buffer, index, &j, &current_centralbank_agent->houses);
						if(rc != 0) { printf("Error: reading 'centralbank' agent variable 'houses' of type 'transaction'\n"); exit(0); } }
				 }else if(in_jpoffice_agent == 1)
				{
					if(in_id) { current_jpoffice_agent->id = atoi(buffer); }
					if(in_it_no) { current_jpoffice_agent->it_no = atoi(buffer); }
					if(in_day_of_month_to_act) { current_jpoffice_agent->day_of_month_to_act = atoi(buffer); }
				 }else if(in_mall_agent == 1)
				{
					if(in_id) { current_mall_agent->id = atoi(buffer); }
					if(in_it_no) { current_mall_agent->it_no = atoi(buffer); }
					if(in_day_of_week_to_act) { current_mall_agent->day_of_week_to_act = atoi(buffer); }
					if(in_goods_transactions) { j = 0;
						rc = read_transaction(buffer, index, &j, &current_mall_agent->goods_transactions);
						if(rc != 0) { printf("Error: reading 'mall' agent variable 'goods_transactions' of type 'transaction'\n"); exit(0); } }
				 }else if(in_reagency_agent == 1)
				{
					if(in_id) { current_reagency_agent->id = atoi(buffer); }
					if(in_day_of_month_to_act) { current_reagency_agent->day_of_month_to_act = atoi(buffer); }
					if(in_it_no) { current_reagency_agent->it_no = atoi(buffer); }
					if(in_mortgages_interest_rate) { current_reagency_agent->mortgages_interest_rate = atof(buffer); }
					if(in_housing_transactions) { j = 0;
						rc = read_transaction(buffer, index, &j, &current_reagency_agent->housing_transactions);
						if(rc != 0) { printf("Error: reading 'reagency' agent variable 'housing_transactions' of type 'transaction'\n"); exit(0); } }
				 }
			}
			index = 0;
			buffer[index] = '\0';
		}
		else
		{
			buffer[index] = c;
			if(index < 99999) index++;
			else
			{
				printf("Error: agent reading buffer too small\n");
				printf("%s\n", buffer);
				exit(0);
			}
		}
	}
	/* Close file */
	(void)fclose(file);

	return 0;
}

/** \fn void check_location_exists(char * location)
 * \brief Check that a directory exists.
 * \param location The directory location to check.
 */
int check_location_exists(char * location)
{
	/* Save a dummy file to directory and remove.
	 * This checks directory exists and is writable */
	FILE * file;
	char * buffer;

	buffer = (char *)malloc( (strlen(location) + strlen("dummy.temp") + 1) * sizeof(char));
	strcpy(buffer, location);
	strcat(buffer, "dummy.temp");

	if((file = fopen(buffer, "w")) == NULL) return 0;

	(void)fclose(file);
	/* Remove dummy file */
	remove(buffer);

	return 1;
}


/** \fn void readinitialstates(char * filename, int * itno, xmachine ** agent_list, double cloud_data[6], int flag)
 * \brief Read initial X-machine memory starting values from a file.
 * \param filename The path to the file.
 * \param filelocation The directory of the location
 * \param itno Pointer to the iteration number.
 * \param agent_list List of agents in the model to be constructed by this function.
 * \param cloud_data Max and min x,y,z coordinates of agents.
 * \param partition_method Identifies partitioning method: 1 = geometric, 2 = round-robin
 * \param flag Flag for whether to check space partitions.
 */
void readinitialstates(char * filename, char * filelocation, int * itno, double cloud_data[],
					   int partition_method, int flag)
{
	/* Pointer to file */
	FILE *file;
	/* Char and char buffer for reading file to */
	char c = '\0';
	char buffer[100000];
	char FLAME_location[10000];
	char FLAME_format[10000];
	char FLAME_type[10000];
	FLAME_output * current_FLAME_output = NULL;

	/* Things for round-robin partitioning */
	int agent_count = 0;
	int number_partitions = 0;
	int geometric=1;
	int other=2;
	

	/* Cloud data array initialisation */
	# ifndef S_SPLINT_S
	cloud_data[0] = SPINF;
	cloud_data[1] = -SPINF;
	cloud_data[2] = SPINF;
	cloud_data[3] = -SPINF;
	cloud_data[4] = SPINF;
	cloud_data[5] = -SPINF;
	# endif

	/* Temporary node and head of associated agent list to allow adding agents */
	node_information temp_node;

	/* Pointer to x-memory for initial state data */
	/*xmachine * current_xmachine;*/
	/* Variables for checking tags */
	int reading = 1;
	int i = 0;
	int rc;
	int in_tag = 0;
	int in_itno = 0;
	int FLAME_in_imports = 0;
	int FLAME_in_import = 0;
	int FLAME_in_outputs = 0;
	int FLAME_in_output = 0;
	int FLAME_in_location = 0;
	int FLAME_in_format = 0;
	int FLAME_in_type = 0;
	int FLAME_in_time = 0;
	int FLAME_in_period = 0;
	int FLAME_in_phase = 0;
	int FLAME_in_name = 0;

	/* Initialise environment vars */
	FLAME_environment_variable_ratio_liquidity = 0.0;
	FLAME_environment_variable_consumption_adjustment_speed = 0.0;
	FLAME_environment_variable_wealth_effect = 0.0;
	FLAME_environment_variable_turnover_probability = 0.0;
	FLAME_environment_variable_production_markup = 0.0;
	FLAME_environment_variable_price_markup = 0.0;
	FLAME_environment_variable_firm_memory_persistance = 0.0;
	FLAME_environment_variable_ratio_fiscal_policy = 0.0;
	FLAME_environment_variable_ratio_capitalist_households = 0.0;
	FLAME_environment_variable_inflation_target = 0.0;
	FLAME_environment_variable_firms_minimum_equity_ratio = 0.0;
	FLAME_environment_variable_firm_startup_leverage = 0.0;
	FLAME_environment_variable_household_startup_leverage = 0.0;
	FLAME_environment_variable_car_buffer_threshold = 0.0;
	FLAME_environment_variable_housing_market_entrance_prob = 0.0;
	FLAME_environment_variable_fire_sale_threshold = 0.0;
	FLAME_environment_variable_household_budget_constraint = 0.0;
	FLAME_environment_variable_capital_adequecy_ratio = 0.0;
	FLAME_environment_variable_housing_price_up_rate = 0.0;
	FLAME_environment_variable_housing_price_down_rate = 0.0;
	FLAME_environment_variable_household_mortgage_writeoff_high = 0.0;
	FLAME_environment_variable_household_mortgage_writeoff_low = 0.0;
	

	/* Open config file to read-only */
	if((file = fopen(filename, "r"))==NULL)
	{
		printf("Error: opening initial states '%s'\n", filename);
		exit(0);
	}
	
	/* Initialise variables */
    *itno = 0;





	if(partition_method==geometric) printf("xml: Geometric partitioning\n");
	else if(partition_method==other) printf("xml: Round-robin partitioning\n");
	else printf("xml: Error - invalid partitioning method\n");


	/* Set p_xmachine to the agent list passed in then new agents are added to this list
	 * Will be set to agent list for specific node is space partitions are already known (flag=1)
	 */
	/* If we're reading without knowing partitions already then use the dummy current node (it's not in the list of nodes)*/
	if (flag == 0) current_node = &temp_node;

	printf("Reading initial data file: %s\n", filename);
	/* Read file until end of xml */
	while(reading==1)
	{
		/* Get the next char from the file */
		c = (char)fgetc(file);

		/* If the end of a tag */
		if(c == '>')
		{
			/* Place 0 at end of buffer to make chars a string */
			buffer[i] = 0;

			if(strcmp(buffer, "states") == 0) reading = 1;
			if(strcmp(buffer, "/states") == 0) reading = 0;
			if(strcmp(buffer, "itno") == 0) in_itno = 1;
			if(strcmp(buffer, "/itno") == 0) in_itno = 0;
			if(strcmp(buffer, "imports") == 0) FLAME_in_imports = 1;
			if(strcmp(buffer, "/imports") == 0) FLAME_in_imports = 0;
			if(strcmp(buffer, "import") == 0)
			{
				/*FLAME_location[0] = '\0';*/
				strcpy(FLAME_location, filelocation);
				FLAME_format[0] = '\0';
				FLAME_type[0] = '\0';

				FLAME_in_import = 1;
			}
			if(strcmp(buffer, "/import") == 0)
			{
				if(strcmp("agent", FLAME_type) == 0 || strcmp("environment", FLAME_type) == 0)
				{
					if(strcmp("xml", FLAME_format) == 0)
					{
						if(strcmp("agent", FLAME_type) == 0) readAgentXML(FLAME_location, cloud_data, partition_method, flag, number_partitions, agent_count, itno);
						if(strcmp("environment", FLAME_type) == 0) readEnvironmentXML(FLAME_location);
					}
					else
					{
						printf("Error: import format '%s' is unsupported\n", FLAME_format);
						exit(0);
					}
				}
				else
				{
					printf("Error: import type '%s' is not agent or environment\n", FLAME_type);
					exit(0);
				}

				FLAME_in_import = 0;
			}
			if(strcmp(buffer, "location") == 0) FLAME_in_location = 1;
			if(strcmp(buffer, "/location") == 0) FLAME_in_location = 0;
			if(strcmp(buffer, "format") == 0) FLAME_in_format = 1;
			if(strcmp(buffer, "/format") == 0) FLAME_in_format = 0;
			if(strcmp(buffer, "type") == 0) FLAME_in_type = 1;
			if(strcmp(buffer, "/type") == 0) FLAME_in_type = 0;
			if(strcmp(buffer, "outputs") == 0) FLAME_in_outputs = 1;
			if(strcmp(buffer, "/outputs") == 0) FLAME_in_outputs = 0;
			if(strcmp(buffer, "output") == 0)
			{
				if(FLAME_in_outputs == 1)
				{
					current_FLAME_output = add_FLAME_output(&FLAME_outputs);
	
					FLAME_in_output = 1;
				}
			}
			if(strcmp(buffer, "/output") == 0)
			{
				if(FLAME_in_outputs == 1)
				{
					if(current_FLAME_output->type == -1)
					{
						printf("Error: an output type has not been set\n");
						exit(0);
					}
					if(current_FLAME_output->format == -1)
					{
						printf("Error: an output format has not been set\n");
						exit(0);
					}
					if(current_FLAME_output->location == NULL)
					{
						printf("Error: an output location has not been set\n");
						exit(0);
					}
					/* If type is xml check if location exists */
					if(current_FLAME_output->type == 0)
					{
						rc = check_location_exists(current_FLAME_output->location);
						if(rc == 0)
						{
							printf("Error: location directory '%s' does not exist\n", current_FLAME_output->location);
							exit(0);
						}
					}
					/* Period has to be larger than 0 */
					if(current_FLAME_output->period < 1)
					{
						printf("Error: output period is less than 1: '%d'\n", current_FLAME_output->period);
						exit(0);
					}
					/* Phase cannot be equal or larger than period */
					if(current_FLAME_output->phase >= current_FLAME_output->period)
					{
						printf("Error: output phase is more or equal to period: '%d'\n", current_FLAME_output->phase);
						exit(0);
					}
	
					FLAME_in_output = 0;
				}
			}
			if(strcmp(buffer, "time") == 0) FLAME_in_time = 1;
			if(strcmp(buffer, "/time") == 0) FLAME_in_time = 0;
			if(strcmp(buffer, "period") == 0) FLAME_in_period = 1;
			if(strcmp(buffer, "/period") == 0) FLAME_in_period = 0;
			if(strcmp(buffer, "phase") == 0) FLAME_in_phase = 1;
			if(strcmp(buffer, "/phase") == 0) FLAME_in_phase = 0;
			if(strcmp(buffer, "name") == 0) FLAME_in_name = 1;
			if(strcmp(buffer, "/name") == 0) FLAME_in_name = 0;

			/* End of tag and reset buffer */
			in_tag = 0;
			i = 0;
		}
		/* If start of tag */
		else if(c == '<')
		{
			/* Place /0 at end of buffer to end numbers */
			buffer[i] = 0;
			/* Flag in tag */
			in_tag = 1;

			if(in_itno) *itno = atoi(buffer);
			if(FLAME_in_imports == 1)
			{
				if(FLAME_in_import == 1)
				{
					if(FLAME_in_location == 1) strcat(FLAME_location, buffer);
					if(FLAME_in_format == 1) strcpy(FLAME_format, buffer);
					if(FLAME_in_type == 1) strcpy(FLAME_type, buffer);
				}
			}
			if(FLAME_in_outputs == 1)
			{
				if(FLAME_in_output == 1)
				{
					if(FLAME_in_type == 1)
					{
						if(strcmp("snapshot", buffer) == 0) current_FLAME_output->type = 0;
						else if(strcmp("agent", buffer) != 0)
						{
							printf("Error: output type is not 'snapshot' or an 'agent': '%s'\n", buffer);
							exit(0);
						}
					}
					if(FLAME_in_name == 1)
					{
						if(strcmp("firm", buffer) == 0) current_FLAME_output->type = 1;
						else if(strcmp("household", buffer) == 0) current_FLAME_output->type = 2;
						else if(strcmp("equityfund", buffer) == 0) current_FLAME_output->type = 3;
						else if(strcmp("bank", buffer) == 0) current_FLAME_output->type = 4;
						else if(strcmp("government", buffer) == 0) current_FLAME_output->type = 5;
						else if(strcmp("centralbank", buffer) == 0) current_FLAME_output->type = 6;
						else if(strcmp("jpoffice", buffer) == 0) current_FLAME_output->type = 7;
						else if(strcmp("mall", buffer) == 0) current_FLAME_output->type = 8;
						else if(strcmp("reagency", buffer) == 0) current_FLAME_output->type = 9;
						else 
						{
							printf("Error: output name is not an agent name: '%s'\n", buffer);
							exit(0);
						}
					}
					if(FLAME_in_format == 1)
					{
						if(strcmp("xml", buffer) == 0) current_FLAME_output->format = 0;
						else
						{
							printf("Error: output format is unsupported: '%s'\n", buffer);
							exit(0);
						}
					}
					if(FLAME_in_location == 1)
					{
						current_FLAME_output->location = (char *)malloc( (strlen(filelocation) + strlen(buffer) + 1) * sizeof(char));
						strcpy(current_FLAME_output->location, filelocation);
						strcat(current_FLAME_output->location, buffer);
					}
					if(FLAME_in_time == 1)
					{
						if(FLAME_in_period == 1) current_FLAME_output->period = atoi(buffer);
						if(FLAME_in_phase == 1)  current_FLAME_output->phase = atoi(buffer);
					}
				}
			}
			/* Reset buffer */
			i = 0;
		}
		/* If in tag put read char into buffer */
		else if(in_tag == 1)
		{
			buffer[i] = c;
			i++;
		}
		/* If in data read char into buffer */
		else
		{
			buffer[i] = c;
			i++;
		}
	}

	/* Close the file */
	(void)fclose(file);

	/* Also try and read environment and agents from 0.xml */
	readEnvironmentXML(filename);
	readAgentXML(filename, cloud_data, partition_method, flag, number_partitions, agent_count, itno);

	/* If outputs is empty add default snapshot for every iteration */
	if(FLAME_outputs == NULL)
	{
		current_FLAME_output = add_FLAME_output(&FLAME_outputs);
		current_FLAME_output->type   = 0; /* snapshot */
		current_FLAME_output->format = 0; /* xml */
		current_FLAME_output->location = (char *)malloc( (strlen(filelocation) +  1) * sizeof(char));
		strcpy(current_FLAME_output->location, filelocation); /* location = 0.xml location */
		current_FLAME_output->period = 1; /* every iteration */
		current_FLAME_output->phase  = 0; /* no phase */
	}
	
	/* Print output settings to CLI */
	for(current_FLAME_output = FLAME_outputs; current_FLAME_output != NULL; current_FLAME_output = current_FLAME_output->next)
	{
		printf("output: type='");
		if(current_FLAME_output->type == 0) printf("snapshot");
		else if(current_FLAME_output->type == 1) printf("agent' name='firm");
		else if(current_FLAME_output->type == 2) printf("agent' name='household");
		else if(current_FLAME_output->type == 3) printf("agent' name='equityfund");
		else if(current_FLAME_output->type == 4) printf("agent' name='bank");
		else if(current_FLAME_output->type == 5) printf("agent' name='government");
		else if(current_FLAME_output->type == 6) printf("agent' name='centralbank");
		else if(current_FLAME_output->type == 7) printf("agent' name='jpoffice");
		else if(current_FLAME_output->type == 8) printf("agent' name='mall");
		else if(current_FLAME_output->type == 9) printf("agent' name='reagency");
		else printf("undefined");
		printf("' format='");
		if(current_FLAME_output->format == 0) printf("xml");
		else printf("undefined");
		printf("' location='%s'", current_FLAME_output->location);
		printf(" period='%d' phase='%d'\n", current_FLAME_output->period, current_FLAME_output->phase);
	}

	/* Make sure cloud data makes sense if any of x,y,z coords were all the same */
	if ( partition_method == geometric ) {
		if ( cloud_data[0] == cloud_data[1] ) {
			cloud_data[0] = -SPINF;
			cloud_data[1] = SPINF;
		}
		if ( cloud_data[2] == cloud_data[3] ) {
			cloud_data[2] = -SPINF;
			cloud_data[3] = SPINF;
		}
		if ( cloud_data[4] == cloud_data[5] ) {
			cloud_data[4] = -SPINF;
			cloud_data[5] = SPINF;
		}
	}
}

/** \fn void write_int_static_array(FILE *file, $name * temp)
 * \brief Writes int.
 */
void write_int_static_array(FILE *file, int * temp, int size)
{
	int i;
	char data[1000];

	fputs("{", file);
	for(i=0; i<size; i++)
	{
		sprintf(data, "%i", temp[i]);
		fputs(data, file);
		if(i < size-1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_float_static_array(FILE *file, float * temp)
 * \brief Writes float.
 */
void write_float_static_array(FILE *file, float * temp, int size)
{
	int i;
	char data[1000];

	fputs("{", file);
	for(i=0; i<size; i++)
	{
		sprintf(data, "%f", temp[i]);
		fputs(data, file);
		if(i < size-1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_double_static_array(FILE *file, double * temp)
 * \brief Writes double.
 */
void write_double_static_array(FILE *file, double * temp, int size)
{
	int i;
	char data[1000];

	fputs("{", file);
	for(i=0; i<size; i++)
	{
		sprintf(data, "%f", temp[i]);
		fputs(data, file);
		if(i < size-1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_char_static_array(FILE *file, char * temp)
 * \brief Writes char.
 */
void write_char_static_array(FILE *file, char * temp, int size)
{
	int i;
	char data[1000];

	//fputs("{", file);
	for(i=0; i<size; i++)
	{
		sprintf(data, "%c", temp[i]);
		fputs(data, file);
		//if(i < size-1) fputs(", ", file);
	}
	//fputs("}", file);
}

/** \fn void write_int_dynamic_array(FILE *file, int_array* temp)
 * \brief Writes int.
 */
void write_int_dynamic_array(FILE *file, int_array * temp)
{
	int i;
	char data[1000];

	fputs("{", file);
	for(i=0; i<(*temp).size; i++)
	{
		sprintf(data, "%i", (*temp).array[i]);
		fputs(data, file);
		if(i < ((*temp).size-1)) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_float_dynamic_array(FILE *file, float_array* temp)
 * \brief Writes float.
 */
void write_float_dynamic_array(FILE *file, float_array * temp)
{
	int i;
	char data[1000];

	fputs("{", file);
	for(i=0; i<(*temp).size; i++)
	{
		sprintf(data, "%f", (*temp).array[i]);
		fputs(data, file);
		if(i < ((*temp).size-1)) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_double_dynamic_array(FILE *file, double_array* temp)
 * \brief Writes double.
 */
void write_double_dynamic_array(FILE *file, double_array * temp)
{
	int i;
	char data[1000];

	fputs("{", file);
	for(i=0; i<(*temp).size; i++)
	{
		sprintf(data, "%f", (*temp).array[i]);
		fputs(data, file);
		if(i < ((*temp).size-1)) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_char_dynamic_array(FILE *file, char_array* temp)
 * \brief Writes char.
 */
void write_char_dynamic_array(FILE *file, char_array * temp)
{
	int i;
	char data[1000];

	for(i=0; i<(*temp).size; i++)
	{
		sprintf(data, "%c", (*temp).array[i]);
		fputs(data, file);
	}
}

/** \fn void write_transaction(FILE *file, transaction * temp_datatype)
 * \brief Writes transaction datatype.
 */
void write_transaction(FILE *file, transaction * temp_datatype)
{
	char data[1000];

	fputs("{", file);
	sprintf(data, "%i", (*temp_datatype).quantity);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).avg_price);
	fputs(data, file);
	fputs("}", file);
}

void write_transaction_static_array(FILE *file, transaction * temp_datatype, int size)
{
	int i;

	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_transaction(file, &temp_datatype[i]);

		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_transaction_dynamic_array(FILE *file, transaction_array * temp_datatype)
{
	int i;

	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_transaction(file, &(*temp_datatype).array[i]);

		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_buyer(FILE *file, buyer * temp_datatype)
 * \brief Writes buyer datatype.
 */
void write_buyer(FILE *file, buyer * temp_datatype)
{
	char data[1000];

	fputs("{", file);
	sprintf(data, "%i", (*temp_datatype).id);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).budget);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).recieved_quantity);
	fputs(data, file);
	fputs("}", file);
}

void write_buyer_static_array(FILE *file, buyer * temp_datatype, int size)
{
	int i;

	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_buyer(file, &temp_datatype[i]);

		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_buyer_dynamic_array(FILE *file, buyer_array * temp_datatype)
{
	int i;

	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_buyer(file, &(*temp_datatype).array[i]);

		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_seller(FILE *file, seller * temp_datatype)
 * \brief Writes seller datatype.
 */
void write_seller(FILE *file, seller * temp_datatype)
{
	char data[1000];

	fputs("{", file);
	sprintf(data, "%i", (*temp_datatype).id);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).price);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).inventory);
	fputs(data, file);
	fputs("}", file);
}

void write_seller_static_array(FILE *file, seller * temp_datatype, int size)
{
	int i;

	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_seller(file, &temp_datatype[i]);

		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_seller_dynamic_array(FILE *file, seller_array * temp_datatype)
{
	int i;

	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_seller(file, &(*temp_datatype).array[i]);

		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_vacancy(FILE *file, vacancy * temp_datatype)
 * \brief Writes vacancy datatype.
 */
void write_vacancy(FILE *file, vacancy * temp_datatype)
{
	char data[1000];

	fputs("{", file);
	sprintf(data, "%i", (*temp_datatype).id);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).wage);
	fputs(data, file);
	fputs("}", file);
}

void write_vacancy_static_array(FILE *file, vacancy * temp_datatype, int size)
{
	int i;

	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_vacancy(file, &temp_datatype[i]);

		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_vacancy_dynamic_array(FILE *file, vacancy_array * temp_datatype)
{
	int i;

	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_vacancy(file, &(*temp_datatype).array[i]);

		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_employee(FILE *file, employee * temp_datatype)
 * \brief Writes employee datatype.
 */
void write_employee(FILE *file, employee * temp_datatype)
{
	char data[1000];

	fputs("{", file);
	sprintf(data, "%i", (*temp_datatype).id);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).wage);
	fputs(data, file);
	fputs("}", file);
}

void write_employee_static_array(FILE *file, employee * temp_datatype, int size)
{
	int i;

	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_employee(file, &temp_datatype[i]);

		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_employee_dynamic_array(FILE *file, employee_array * temp_datatype)
{
	int i;

	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_employee(file, &(*temp_datatype).array[i]);

		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_mortgage(FILE *file, mortgage * temp_datatype)
 * \brief Writes mortgage datatype.
 */
void write_mortgage(FILE *file, mortgage * temp_datatype)
{
	char data[1000];

	fputs("{", file);
	sprintf(data, "%i", (*temp_datatype).bank_id);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).principal);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).quarters_left);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).quarterly_interest);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).quarterly_principal);
	fputs(data, file);
	fputs("}", file);
}

void write_mortgage_static_array(FILE *file, mortgage * temp_datatype, int size)
{
	int i;

	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_mortgage(file, &temp_datatype[i]);

		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_mortgage_dynamic_array(FILE *file, mortgage_array * temp_datatype)
{
	int i;

	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_mortgage(file, &(*temp_datatype).array[i]);

		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_loan(FILE *file, loan * temp_datatype)
 * \brief Writes loan datatype.
 */
void write_loan(FILE *file, loan * temp_datatype)
{
	char data[1000];

	fputs("{", file);
	sprintf(data, "%i", (*temp_datatype).bank_id);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).amount);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).to_be_paid);
	fputs(data, file);
	fputs("}", file);
}

void write_loan_static_array(FILE *file, loan * temp_datatype, int size)
{
	int i;

	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_loan(file, &temp_datatype[i]);

		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_loan_dynamic_array(FILE *file, loan_array * temp_datatype)
{
	int i;

	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_loan(file, &(*temp_datatype).array[i]);

		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_hbuyer(FILE *file, hbuyer * temp_datatype)
 * \brief Writes hbuyer datatype.
 */
void write_hbuyer(FILE *file, hbuyer * temp_datatype)
{
	char data[1000];

	fputs("{", file);
	sprintf(data, "%i", (*temp_datatype).buyer_id);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).bank_id);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).liquidity);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).quarterly_income);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).quarterly_mortgage_paid);
	fputs(data, file);
	fputs("}", file);
}

void write_hbuyer_static_array(FILE *file, hbuyer * temp_datatype, int size)
{
	int i;

	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_hbuyer(file, &temp_datatype[i]);

		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_hbuyer_dynamic_array(FILE *file, hbuyer_array * temp_datatype)
{
	int i;

	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_hbuyer(file, &(*temp_datatype).array[i]);

		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_hseller(FILE *file, hseller * temp_datatype)
 * \brief Writes hseller datatype.
 */
void write_hseller(FILE *file, hseller * temp_datatype)
{
	char data[1000];

	fputs("{", file);
	sprintf(data, "%i", (*temp_datatype).seller_id);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).price);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).quantity);
	fputs(data, file);
	fputs("}", file);
}

void write_hseller_static_array(FILE *file, hseller * temp_datatype, int size)
{
	int i;

	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_hseller(file, &temp_datatype[i]);

		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_hseller_dynamic_array(FILE *file, hseller_array * temp_datatype)
{
	int i;

	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_hseller(file, &(*temp_datatype).array[i]);

		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_hbank(FILE *file, hbank * temp_datatype)
 * \brief Writes hbank datatype.
 */
void write_hbank(FILE *file, hbank * temp_datatype)
{
	char data[1000];

	fputs("{", file);
	sprintf(data, "%i", (*temp_datatype).id);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).equity);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).risky_assets);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).amount_mortgaged);
	fputs(data, file);
	fputs("}", file);
}

void write_hbank_static_array(FILE *file, hbank * temp_datatype, int size)
{
	int i;

	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_hbank(file, &temp_datatype[i]);

		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_hbank_dynamic_array(FILE *file, hbank_array * temp_datatype)
{
	int i;

	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_hbank(file, &(*temp_datatype).array[i]);

		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}



void write_firm_agent(FILE *file, xmachine_memory_firm * current)
{
	char data[1000];
	fputs("<xagent>\n" , file);
	fputs("<name>firm</name>\n", file);
		fputs("<id>", file);
	sprintf(data, "%i", current->id);
	fputs(data, file);
	fputs("</id>\n", file);
		fputs("<bank_id>", file);
	sprintf(data, "%i", current->bank_id);
	fputs(data, file);
	fputs("</bank_id>\n", file);
		fputs("<isconstructor>", file);
	sprintf(data, "%i", current->isconstructor);
	fputs(data, file);
	fputs("</isconstructor>\n", file);
		fputs("<day_of_month_to_act>", file);
	sprintf(data, "%i", current->day_of_month_to_act);
	fputs(data, file);
	fputs("</day_of_month_to_act>\n", file);
		fputs("<isinsolvent>", file);
	sprintf(data, "%i", current->isinsolvent);
	fputs(data, file);
	fputs("</isinsolvent>\n", file);
		fputs("<it_no>", file);
	sprintf(data, "%i", current->it_no);
	fputs(data, file);
	fputs("</it_no>\n", file);
		fputs("<day_of_week_to_act>", file);
	sprintf(data, "%i", current->day_of_week_to_act);
	fputs(data, file);
	fputs("</day_of_week_to_act>\n", file);
		fputs("<average_goods_price>", file);
	sprintf(data, "%f", current->average_goods_price);
	fputs(data, file);
	fputs("</average_goods_price>\n", file);
		fputs("<employees>", file);
	write_int_dynamic_array(file, &current->employees);
	fputs("</employees>\n", file);
		fputs("<wage_offer>", file);
	sprintf(data, "%f", current->wage_offer);
	fputs(data, file);
	fputs("</wage_offer>\n", file);
		fputs("<average_wage>", file);
	sprintf(data, "%f", current->average_wage);
	fputs(data, file);
	fputs("</average_wage>\n", file);
		fputs("<no_employees>", file);
	sprintf(data, "%i", current->no_employees);
	fputs(data, file);
	fputs("</no_employees>\n", file);
		fputs("<vacancies>", file);
	sprintf(data, "%i", current->vacancies);
	fputs(data, file);
	fputs("</vacancies>\n", file);
		fputs("<employees_needed>", file);
	sprintf(data, "%i", current->employees_needed);
	fputs(data, file);
	fputs("</employees_needed>\n", file);
		fputs("<day_of_month_wages_paid>", file);
	sprintf(data, "%i", current->day_of_month_wages_paid);
	fputs(data, file);
	fputs("</day_of_month_wages_paid>\n", file);
		fputs("<labour_productivity>", file);
	sprintf(data, "%f", current->labour_productivity);
	fputs(data, file);
	fputs("</labour_productivity>\n", file);
		fputs("<production_current>", file);
	sprintf(data, "%i", current->production_current);
	fputs(data, file);
	fputs("</production_current>\n", file);
		fputs("<expected_sales>", file);
	sprintf(data, "%i", current->expected_sales);
	fputs(data, file);
	fputs("</expected_sales>\n", file);
		fputs("<production_plan>", file);
	sprintf(data, "%i", current->production_plan);
	fputs(data, file);
	fputs("</production_plan>\n", file);
		fputs("<unit_goods_price>", file);
	sprintf(data, "%f", current->unit_goods_price);
	fputs(data, file);
	fputs("</unit_goods_price>\n", file);
		fputs("<unit_cost>", file);
	sprintf(data, "%f", current->unit_cost);
	fputs(data, file);
	fputs("</unit_cost>\n", file);
		fputs("<day_of_month_production_completed>", file);
	sprintf(data, "%i", current->day_of_month_production_completed);
	fputs(data, file);
	fputs("</day_of_month_production_completed>\n", file);
		fputs("<unit_house_price>", file);
	sprintf(data, "%f", current->unit_house_price);
	fputs(data, file);
	fputs("</unit_house_price>\n", file);
		fputs("<labour_productivity_construction>", file);
	sprintf(data, "%f", current->labour_productivity_construction);
	fputs(data, file);
	fputs("</labour_productivity_construction>\n", file);
		fputs("<capital_productivity_construction>", file);
	sprintf(data, "%f", current->capital_productivity_construction);
	fputs(data, file);
	fputs("</capital_productivity_construction>\n", file);
		fputs("<capital_construction>", file);
	sprintf(data, "%f", current->capital_construction);
	fputs(data, file);
	fputs("</capital_construction>\n", file);
		fputs("<physical_capital>", file);
	sprintf(data, "%f", current->physical_capital);
	fputs(data, file);
	fputs("</physical_capital>\n", file);
		fputs("<projects>", file);
	write_int_static_array(file, current->projects, 12);
	fputs("</projects>\n", file);
		fputs("<loans_interest_rate>", file);
	sprintf(data, "%f", current->loans_interest_rate);
	fputs(data, file);
	fputs("</loans_interest_rate>\n", file);
		fputs("<debt>", file);
	sprintf(data, "%f", current->debt);
	fputs(data, file);
	fputs("</debt>\n", file);
		fputs("<inventory>", file);
	sprintf(data, "%i", current->inventory);
	fputs(data, file);
	fputs("</inventory>\n", file);
		fputs("<sales>", file);
	sprintf(data, "%i", current->sales);
	fputs(data, file);
	fputs("</sales>\n", file);
		fputs("<revenues>", file);
	sprintf(data, "%f", current->revenues);
	fputs(data, file);
	fputs("</revenues>\n", file);
		fputs("<total_assets>", file);
	sprintf(data, "%f", current->total_assets);
	fputs(data, file);
	fputs("</total_assets>\n", file);
		fputs("<operating_costs>", file);
	sprintf(data, "%f", current->operating_costs);
	fputs(data, file);
	fputs("</operating_costs>\n", file);
		fputs("<labour_costs>", file);
	sprintf(data, "%f", current->labour_costs);
	fputs(data, file);
	fputs("</labour_costs>\n", file);
		fputs("<total_interest_payments>", file);
	sprintf(data, "%f", current->total_interest_payments);
	fputs(data, file);
	fputs("</total_interest_payments>\n", file);
		fputs("<dividends_paid>", file);
	sprintf(data, "%f", current->dividends_paid);
	fputs(data, file);
	fputs("</dividends_paid>\n", file);
		fputs("<dividends_to_be_paid>", file);
	sprintf(data, "%f", current->dividends_to_be_paid);
	fputs(data, file);
	fputs("</dividends_to_be_paid>\n", file);
		fputs("<retained_earnings>", file);
	sprintf(data, "%f", current->retained_earnings);
	fputs(data, file);
	fputs("</retained_earnings>\n", file);
		fputs("<net_earnings>", file);
	sprintf(data, "%f", current->net_earnings);
	fputs(data, file);
	fputs("</net_earnings>\n", file);
		fputs("<ebit>", file);
	sprintf(data, "%f", current->ebit);
	fputs(data, file);
	fputs("</ebit>\n", file);
		fputs("<equity>", file);
	sprintf(data, "%f", current->equity);
	fputs(data, file);
	fputs("</equity>\n", file);
		fputs("<liquidity>", file);
	sprintf(data, "%f", current->liquidity);
	fputs(data, file);
	fputs("</liquidity>\n", file);
		fputs("<capital_goods>", file);
	sprintf(data, "%f", current->capital_goods);
	fputs(data, file);
	fputs("</capital_goods>\n", file);
		fputs("<capital_goods_price>", file);
	sprintf(data, "%f", current->capital_goods_price);
	fputs(data, file);
	fputs("</capital_goods_price>\n", file);
		fputs("<hasloan>", file);
	sprintf(data, "%i", current->hasloan);
	fputs(data, file);
	fputs("</hasloan>\n", file);
		fputs("<hasinvestment>", file);
	sprintf(data, "%i", current->hasinvestment);
	fputs(data, file);
	fputs("</hasinvestment>\n", file);
		fputs("<planned_investment_costs>", file);
	sprintf(data, "%f", current->planned_investment_costs);
	fputs(data, file);
	fputs("</planned_investment_costs>\n", file);
		fputs("<liquidity_need>", file);
	sprintf(data, "%f", current->liquidity_need);
	fputs(data, file);
	fputs("</liquidity_need>\n", file);
		fputs("<loan_list>", file);
	write_loan_static_array(file, current->loan_list, 2);
	fputs("</loan_list>\n", file);
		fputs("<labour_tax_rate>", file);
	sprintf(data, "%f", current->labour_tax_rate);
	fputs(data, file);
	fputs("</labour_tax_rate>\n", file);
		fputs("<delta_housing_price>", file);
	sprintf(data, "%f", current->delta_housing_price);
	fputs(data, file);
	fputs("</delta_housing_price>\n", file);

	fputs("</xagent>\n", file);
}

void write_household_agent(FILE *file, xmachine_memory_household * current)
{
	char data[1000];
	fputs("<xagent>\n" , file);
	fputs("<name>household</name>\n", file);
		fputs("<id>", file);
	sprintf(data, "%i", current->id);
	fputs(data, file);
	fputs("</id>\n", file);
		fputs("<bank_id>", file);
	sprintf(data, "%i", current->bank_id);
	fputs(data, file);
	fputs("</bank_id>\n", file);
		fputs("<it_no>", file);
	sprintf(data, "%i", current->it_no);
	fputs(data, file);
	fputs("</it_no>\n", file);
		fputs("<day_of_week_to_act>", file);
	sprintf(data, "%i", current->day_of_week_to_act);
	fputs(data, file);
	fputs("</day_of_week_to_act>\n", file);
		fputs("<weekly_consumption_budget>", file);
	sprintf(data, "%f", current->weekly_consumption_budget);
	fputs(data, file);
	fputs("</weekly_consumption_budget>\n", file);
		fputs("<planned_consumption_budget>", file);
	sprintf(data, "%f", current->planned_consumption_budget);
	fputs(data, file);
	fputs("</planned_consumption_budget>\n", file);
		fputs("<my_employer_id>", file);
	sprintf(data, "%i", current->my_employer_id);
	fputs(data, file);
	fputs("</my_employer_id>\n", file);
		fputs("<wage>", file);
	sprintf(data, "%f", current->wage);
	fputs(data, file);
	fputs("</wage>\n", file);
		fputs("<day_of_month_to_act>", file);
	sprintf(data, "%i", current->day_of_month_to_act);
	fputs(data, file);
	fputs("</day_of_month_to_act>\n", file);
		fputs("<day_of_month_wage_recieved>", file);
	sprintf(data, "%i", current->day_of_month_wage_recieved);
	fputs(data, file);
	fputs("</day_of_month_wage_recieved>\n", file);
		fputs("<mortgages_interest_rate>", file);
	sprintf(data, "%f", current->mortgages_interest_rate);
	fputs(data, file);
	fputs("</mortgages_interest_rate>\n", file);
		fputs("<labour_tax_rate>", file);
	sprintf(data, "%f", current->labour_tax_rate);
	fputs(data, file);
	fputs("</labour_tax_rate>\n", file);
		fputs("<mortgages_list>", file);
	write_mortgage_dynamic_array(file, &current->mortgages_list);
	fputs("</mortgages_list>\n", file);
		fputs("<mortgages>", file);
	sprintf(data, "%f", current->mortgages);
	fputs(data, file);
	fputs("</mortgages>\n", file);
		fputs("<housing_payment>", file);
	sprintf(data, "%f", current->housing_payment);
	fputs(data, file);
	fputs("</housing_payment>\n", file);
		fputs("<equity>", file);
	sprintf(data, "%f", current->equity);
	fputs(data, file);
	fputs("</equity>\n", file);
		fputs("<housing_price>", file);
	sprintf(data, "%f", current->housing_price);
	fputs(data, file);
	fputs("</housing_price>\n", file);
		fputs("<housing_units>", file);
	sprintf(data, "%i", current->housing_units);
	fputs(data, file);
	fputs("</housing_units>\n", file);
		fputs("<n_shares>", file);
	sprintf(data, "%i", current->n_shares);
	fputs(data, file);
	fputs("</n_shares>\n", file);
		fputs("<liquidity>", file);
	sprintf(data, "%f", current->liquidity);
	fputs(data, file);
	fputs("</liquidity>\n", file);
		fputs("<capital_income>", file);
	sprintf(data, "%f", current->capital_income);
	fputs(data, file);
	fputs("</capital_income>\n", file);
		fputs("<previous_wages>", file);
	write_int_static_array(file, current->previous_wages, 3);
	fputs("</previous_wages>\n", file);
		fputs("<labour_income>", file);
	sprintf(data, "%f", current->labour_income);
	fputs(data, file);
	fputs("</labour_income>\n", file);
		fputs("<total_assets>", file);
	sprintf(data, "%f", current->total_assets);
	fputs(data, file);
	fputs("</total_assets>\n", file);
		fputs("<housing_value>", file);
	sprintf(data, "%f", current->housing_value);
	fputs(data, file);
	fputs("</housing_value>\n", file);
		fputs("<delta_housing_value>", file);
	sprintf(data, "%f", current->delta_housing_value);
	fputs(data, file);
	fputs("</delta_housing_value>\n", file);
		fputs("<hmarket_role>", file);
	sprintf(data, "%i", current->hmarket_role);
	fputs(data, file);
	fputs("</hmarket_role>\n", file);
		fputs("<equity_ratio>", file);
	sprintf(data, "%f", current->equity_ratio);
	fputs(data, file);
	fputs("</equity_ratio>\n", file);
		fputs("<minimum_equity_ratio>", file);
	sprintf(data, "%f", current->minimum_equity_ratio);
	fputs(data, file);
	fputs("</minimum_equity_ratio>\n", file);
		fputs("<mortgage_costs>", file);
	write_double_static_array(file, current->mortgage_costs, 3);
	fputs("</mortgage_costs>\n", file);

	fputs("</xagent>\n", file);
}

void write_equityfund_agent(FILE *file, xmachine_memory_equityfund * current)
{
	char data[1000];
	fputs("<xagent>\n" , file);
	fputs("<name>equityfund</name>\n", file);
		fputs("<id>", file);
	sprintf(data, "%i", current->id);
	fputs(data, file);
	fputs("</id>\n", file);
		fputs("<it_no>", file);
	sprintf(data, "%i", current->it_no);
	fputs(data, file);
	fputs("</it_no>\n", file);
		fputs("<day_of_month_to_act>", file);
	sprintf(data, "%i", current->day_of_month_to_act);
	fputs(data, file);
	fputs("</day_of_month_to_act>\n", file);
		fputs("<share_firms>", file);
	sprintf(data, "%f", current->share_firms);
	fputs(data, file);
	fputs("</share_firms>\n", file);
		fputs("<share_construction_firms>", file);
	sprintf(data, "%f", current->share_construction_firms);
	fputs(data, file);
	fputs("</share_construction_firms>\n", file);
		fputs("<share_banks>", file);
	sprintf(data, "%f", current->share_banks);
	fputs(data, file);
	fputs("</share_banks>\n", file);
		fputs("<equity>", file);
	sprintf(data, "%f", current->equity);
	fputs(data, file);
	fputs("</equity>\n", file);
		fputs("<liquidity>", file);
	sprintf(data, "%f", current->liquidity);
	fputs(data, file);
	fputs("</liquidity>\n", file);
		fputs("<n_shares>", file);
	sprintf(data, "%i", current->n_shares);
	fputs(data, file);
	fputs("</n_shares>\n", file);
		fputs("<dividends_recieved>", file);
	sprintf(data, "%f", current->dividends_recieved);
	fputs(data, file);
	fputs("</dividends_recieved>\n", file);
		fputs("<dividends_retained>", file);
	sprintf(data, "%f", current->dividends_retained);
	fputs(data, file);
	fputs("</dividends_retained>\n", file);
		fputs("<dividends_paid>", file);
	sprintf(data, "%f", current->dividends_paid);
	fputs(data, file);
	fputs("</dividends_paid>\n", file);
		fputs("<firm_investment>", file);
	sprintf(data, "%f", current->firm_investment);
	fputs(data, file);
	fputs("</firm_investment>\n", file);
		fputs("<capital_tax_rate>", file);
	sprintf(data, "%f", current->capital_tax_rate);
	fputs(data, file);
	fputs("</capital_tax_rate>\n", file);

	fputs("</xagent>\n", file);
}

void write_bank_agent(FILE *file, xmachine_memory_bank * current)
{
	char data[1000];
	fputs("<xagent>\n" , file);
	fputs("<name>bank</name>\n", file);
		fputs("<id>", file);
	sprintf(data, "%i", current->id);
	fputs(data, file);
	fputs("</id>\n", file);
		fputs("<day_of_month_to_act>", file);
	sprintf(data, "%i", current->day_of_month_to_act);
	fputs(data, file);
	fputs("</day_of_month_to_act>\n", file);
		fputs("<day_of_week_to_act>", file);
	sprintf(data, "%i", current->day_of_week_to_act);
	fputs(data, file);
	fputs("</day_of_week_to_act>\n", file);
		fputs("<it_no>", file);
	sprintf(data, "%i", current->it_no);
	fputs(data, file);
	fputs("</it_no>\n", file);
		fputs("<total_assets>", file);
	sprintf(data, "%f", current->total_assets);
	fputs(data, file);
	fputs("</total_assets>\n", file);
		fputs("<loans>", file);
	sprintf(data, "%f", current->loans);
	fputs(data, file);
	fputs("</loans>\n", file);
		fputs("<mortgages>", file);
	sprintf(data, "%f", current->mortgages);
	fputs(data, file);
	fputs("</mortgages>\n", file);
		fputs("<deposits>", file);
	sprintf(data, "%f", current->deposits);
	fputs(data, file);
	fputs("</deposits>\n", file);
		fputs("<centralbank_debt>", file);
	sprintf(data, "%f", current->centralbank_debt);
	fputs(data, file);
	fputs("</centralbank_debt>\n", file);
		fputs("<equity>", file);
	sprintf(data, "%f", current->equity);
	fputs(data, file);
	fputs("</equity>\n", file);
		fputs("<liquidity>", file);
	sprintf(data, "%f", current->liquidity);
	fputs(data, file);
	fputs("</liquidity>\n", file);
		fputs("<revenues>", file);
	sprintf(data, "%f", current->revenues);
	fputs(data, file);
	fputs("</revenues>\n", file);
		fputs("<total_writeoffs>", file);
	sprintf(data, "%f", current->total_writeoffs);
	fputs(data, file);
	fputs("</total_writeoffs>\n", file);
		fputs("<interest_rate>", file);
	sprintf(data, "%f", current->interest_rate);
	fputs(data, file);
	fputs("</interest_rate>\n", file);
		fputs("<interests_accrued>", file);
	sprintf(data, "%f", current->interests_accrued);
	fputs(data, file);
	fputs("</interests_accrued>\n", file);
		fputs("<interests_paid>", file);
	sprintf(data, "%f", current->interests_paid);
	fputs(data, file);
	fputs("</interests_paid>\n", file);
		fputs("<dividends_paid>", file);
	sprintf(data, "%f", current->dividends_paid);
	fputs(data, file);
	fputs("</dividends_paid>\n", file);
		fputs("<total_dividends>", file);
	sprintf(data, "%f", current->total_dividends);
	fputs(data, file);
	fputs("</total_dividends>\n", file);
		fputs("<retained_earnings>", file);
	sprintf(data, "%f", current->retained_earnings);
	fputs(data, file);
	fputs("</retained_earnings>\n", file);
		fputs("<net_earnings>", file);
	sprintf(data, "%f", current->net_earnings);
	fputs(data, file);
	fputs("</net_earnings>\n", file);
		fputs("<total_costs>", file);
	sprintf(data, "%f", current->total_costs);
	fputs(data, file);
	fputs("</total_costs>\n", file);

	fputs("</xagent>\n", file);
}

void write_government_agent(FILE *file, xmachine_memory_government * current)
{
	char data[1000];
	fputs("<xagent>\n" , file);
	fputs("<name>government</name>\n", file);
		fputs("<id>", file);
	sprintf(data, "%i", current->id);
	fputs(data, file);
	fputs("</id>\n", file);
		fputs("<it_no>", file);
	sprintf(data, "%i", current->it_no);
	fputs(data, file);
	fputs("</it_no>\n", file);
		fputs("<average_wage>", file);
	sprintf(data, "%f", current->average_wage);
	fputs(data, file);
	fputs("</average_wage>\n", file);
		fputs("<unemployment_rate>", file);
	sprintf(data, "%f", current->unemployment_rate);
	fputs(data, file);
	fputs("</unemployment_rate>\n", file);
		fputs("<population_size>", file);
	sprintf(data, "%i", current->population_size);
	fputs(data, file);
	fputs("</population_size>\n", file);
		fputs("<debt>", file);
	sprintf(data, "%f", current->debt);
	fputs(data, file);
	fputs("</debt>\n", file);
		fputs("<equity>", file);
	sprintf(data, "%f", current->equity);
	fputs(data, file);
	fputs("</equity>\n", file);
		fputs("<liquidity>", file);
	sprintf(data, "%f", current->liquidity);
	fputs(data, file);
	fputs("</liquidity>\n", file);
		fputs("<day_of_month_to_act>", file);
	sprintf(data, "%i", current->day_of_month_to_act);
	fputs(data, file);
	fputs("</day_of_month_to_act>\n", file);
		fputs("<day_of_month_wages_paid>", file);
	sprintf(data, "%i", current->day_of_month_wages_paid);
	fputs(data, file);
	fputs("</day_of_month_wages_paid>\n", file);
		fputs("<capital_tax_rate>", file);
	sprintf(data, "%f", current->capital_tax_rate);
	fputs(data, file);
	fputs("</capital_tax_rate>\n", file);
		fputs("<labour_tax_rate>", file);
	sprintf(data, "%f", current->labour_tax_rate);
	fputs(data, file);
	fputs("</labour_tax_rate>\n", file);
		fputs("<labour_tax_income>", file);
	sprintf(data, "%f", current->labour_tax_income);
	fputs(data, file);
	fputs("</labour_tax_income>\n", file);
		fputs("<capital_tax_income>", file);
	sprintf(data, "%f", current->capital_tax_income);
	fputs(data, file);
	fputs("</capital_tax_income>\n", file);
		fputs("<gov_general_benefit_rate>", file);
	sprintf(data, "%f", current->gov_general_benefit_rate);
	fputs(data, file);
	fputs("</gov_general_benefit_rate>\n", file);
		fputs("<gov_unemployment_rate>", file);
	sprintf(data, "%f", current->gov_unemployment_rate);
	fputs(data, file);
	fputs("</gov_unemployment_rate>\n", file);
		fputs("<general_benefits>", file);
	sprintf(data, "%f", current->general_benefits);
	fputs(data, file);
	fputs("</general_benefits>\n", file);
		fputs("<unemployment_benefits>", file);
	sprintf(data, "%f", current->unemployment_benefits);
	fputs(data, file);
	fputs("</unemployment_benefits>\n", file);
		fputs("<earnings>", file);
	sprintf(data, "%f", current->earnings);
	fputs(data, file);
	fputs("</earnings>\n", file);
		fputs("<centralbank_income>", file);
	sprintf(data, "%f", current->centralbank_income);
	fputs(data, file);
	fputs("</centralbank_income>\n", file);
		fputs("<expenditures>", file);
	sprintf(data, "%f", current->expenditures);
	fputs(data, file);
	fputs("</expenditures>\n", file);

	fputs("</xagent>\n", file);
}

void write_centralbank_agent(FILE *file, xmachine_memory_centralbank * current)
{
	char data[1000];
	fputs("<xagent>\n" , file);
	fputs("<name>centralbank</name>\n", file);
		fputs("<id>", file);
	sprintf(data, "%i", current->id);
	fputs(data, file);
	fputs("</id>\n", file);
		fputs("<day_of_month_to_act>", file);
	sprintf(data, "%i", current->day_of_month_to_act);
	fputs(data, file);
	fputs("</day_of_month_to_act>\n", file);
		fputs("<unemployment_rate>", file);
	sprintf(data, "%f", current->unemployment_rate);
	fputs(data, file);
	fputs("</unemployment_rate>\n", file);
		fputs("<consumption_goods_prices>", file);
	write_double_static_array(file, current->consumption_goods_prices, 12);
	fputs("</consumption_goods_prices>\n", file);
		fputs("<it_no>", file);
	sprintf(data, "%i", current->it_no);
	fputs(data, file);
	fputs("</it_no>\n", file);
		fputs("<day_of_week_to_act>", file);
	sprintf(data, "%i", current->day_of_week_to_act);
	fputs(data, file);
	fputs("</day_of_week_to_act>\n", file);
		fputs("<goods>", file);
	write_transaction(file, &current->goods);
	fputs("</goods>\n", file);
		fputs("<weekly_price_averages>", file);
	write_double_static_array(file, current->weekly_price_averages, 4);
	fputs("</weekly_price_averages>\n", file);
		fputs("<interest_rate>", file);
	sprintf(data, "%f", current->interest_rate);
	fputs(data, file);
	fputs("</interest_rate>\n", file);
		fputs("<liquidity>", file);
	sprintf(data, "%f", current->liquidity);
	fputs(data, file);
	fputs("</liquidity>\n", file);
		fputs("<loans_banks>", file);
	sprintf(data, "%f", current->loans_banks);
	fputs(data, file);
	fputs("</loans_banks>\n", file);
		fputs("<loans_government>", file);
	sprintf(data, "%f", current->loans_government);
	fputs(data, file);
	fputs("</loans_government>\n", file);
		fputs("<fiat_money>", file);
	sprintf(data, "%f", current->fiat_money);
	fputs(data, file);
	fputs("</fiat_money>\n", file);
		fputs("<equity>", file);
	sprintf(data, "%f", current->equity);
	fputs(data, file);
	fputs("</equity>\n", file);
		fputs("<liquidity_banks>", file);
	sprintf(data, "%f", current->liquidity_banks);
	fputs(data, file);
	fputs("</liquidity_banks>\n", file);
		fputs("<liquidity_government>", file);
	sprintf(data, "%f", current->liquidity_government);
	fputs(data, file);
	fputs("</liquidity_government>\n", file);
		fputs("<total_assets>", file);
	sprintf(data, "%f", current->total_assets);
	fputs(data, file);
	fputs("</total_assets>\n", file);
		fputs("<total_writeoffs>", file);
	sprintf(data, "%f", current->total_writeoffs);
	fputs(data, file);
	fputs("</total_writeoffs>\n", file);
		fputs("<interests_accrued>", file);
	sprintf(data, "%f", current->interests_accrued);
	fputs(data, file);
	fputs("</interests_accrued>\n", file);
		fputs("<revenues>", file);
	sprintf(data, "%f", current->revenues);
	fputs(data, file);
	fputs("</revenues>\n", file);
		fputs("<net_earnings>", file);
	sprintf(data, "%f", current->net_earnings);
	fputs(data, file);
	fputs("</net_earnings>\n", file);
		fputs("<total_costs>", file);
	sprintf(data, "%f", current->total_costs);
	fputs(data, file);
	fputs("</total_costs>\n", file);
		fputs("<houses>", file);
	write_transaction(file, &current->houses);
	fputs("</houses>\n", file);

	fputs("</xagent>\n", file);
}

void write_jpoffice_agent(FILE *file, xmachine_memory_jpoffice * current)
{
	char data[1000];
	fputs("<xagent>\n" , file);
	fputs("<name>jpoffice</name>\n", file);
		fputs("<id>", file);
	sprintf(data, "%i", current->id);
	fputs(data, file);
	fputs("</id>\n", file);
		fputs("<it_no>", file);
	sprintf(data, "%i", current->it_no);
	fputs(data, file);
	fputs("</it_no>\n", file);
		fputs("<day_of_month_to_act>", file);
	sprintf(data, "%i", current->day_of_month_to_act);
	fputs(data, file);
	fputs("</day_of_month_to_act>\n", file);

	fputs("</xagent>\n", file);
}

void write_mall_agent(FILE *file, xmachine_memory_mall * current)
{
	char data[1000];
	fputs("<xagent>\n" , file);
	fputs("<name>mall</name>\n", file);
		fputs("<id>", file);
	sprintf(data, "%i", current->id);
	fputs(data, file);
	fputs("</id>\n", file);
		fputs("<it_no>", file);
	sprintf(data, "%i", current->it_no);
	fputs(data, file);
	fputs("</it_no>\n", file);
		fputs("<day_of_week_to_act>", file);
	sprintf(data, "%i", current->day_of_week_to_act);
	fputs(data, file);
	fputs("</day_of_week_to_act>\n", file);
		fputs("<goods_transactions>", file);
	write_transaction(file, &current->goods_transactions);
	fputs("</goods_transactions>\n", file);

	fputs("</xagent>\n", file);
}

void write_reagency_agent(FILE *file, xmachine_memory_reagency * current)
{
	char data[1000];
	fputs("<xagent>\n" , file);
	fputs("<name>reagency</name>\n", file);
		fputs("<id>", file);
	sprintf(data, "%i", current->id);
	fputs(data, file);
	fputs("</id>\n", file);
		fputs("<day_of_month_to_act>", file);
	sprintf(data, "%i", current->day_of_month_to_act);
	fputs(data, file);
	fputs("</day_of_month_to_act>\n", file);
		fputs("<it_no>", file);
	sprintf(data, "%i", current->it_no);
	fputs(data, file);
	fputs("</it_no>\n", file);
		fputs("<mortgages_interest_rate>", file);
	sprintf(data, "%f", current->mortgages_interest_rate);
	fputs(data, file);
	fputs("</mortgages_interest_rate>\n", file);
		fputs("<housing_transactions>", file);
	write_transaction(file, &current->housing_transactions);
	fputs("</housing_transactions>\n", file);

	fputs("</xagent>\n", file);
}


void FLAME_write_xml(char * location, int iteration_number, int * output_types, int output_type_size)
{
	/* Pointer to file */
	FILE *file;
	char data[1000];
	
		sprintf(data, "%s%i.xml", location, iteration_number);
	
	if((file = fopen(data, "w"))==NULL)
	{
		printf("Error: cannot open file '%s' for writing\n", data);
		exit(0);
	}
	
	
	fputs("<states>\n", file);
	if(FLAME_integer_in_array(0, output_types, output_type_size))
	{
		fputs("<itno>", file);
		sprintf(data, "%i", iteration_number);
		fputs(data, file);
		fputs("</itno>\n", file);
		fputs("<environment>\n" , file);
			fputs("<ratio_liquidity>", file);
		sprintf(data, "%f", FLAME_environment_variable_ratio_liquidity);
		fputs(data, file);
		fputs("</ratio_liquidity>\n", file);
			fputs("<consumption_adjustment_speed>", file);
		sprintf(data, "%f", FLAME_environment_variable_consumption_adjustment_speed);
		fputs(data, file);
		fputs("</consumption_adjustment_speed>\n", file);
			fputs("<wealth_effect>", file);
		sprintf(data, "%f", FLAME_environment_variable_wealth_effect);
		fputs(data, file);
		fputs("</wealth_effect>\n", file);
			fputs("<turnover_probability>", file);
		sprintf(data, "%f", FLAME_environment_variable_turnover_probability);
		fputs(data, file);
		fputs("</turnover_probability>\n", file);
			fputs("<production_markup>", file);
		sprintf(data, "%f", FLAME_environment_variable_production_markup);
		fputs(data, file);
		fputs("</production_markup>\n", file);
			fputs("<price_markup>", file);
		sprintf(data, "%f", FLAME_environment_variable_price_markup);
		fputs(data, file);
		fputs("</price_markup>\n", file);
			fputs("<firm_memory_persistance>", file);
		sprintf(data, "%f", FLAME_environment_variable_firm_memory_persistance);
		fputs(data, file);
		fputs("</firm_memory_persistance>\n", file);
			fputs("<ratio_fiscal_policy>", file);
		sprintf(data, "%f", FLAME_environment_variable_ratio_fiscal_policy);
		fputs(data, file);
		fputs("</ratio_fiscal_policy>\n", file);
			fputs("<ratio_capitalist_households>", file);
		sprintf(data, "%f", FLAME_environment_variable_ratio_capitalist_households);
		fputs(data, file);
		fputs("</ratio_capitalist_households>\n", file);
			fputs("<inflation_target>", file);
		sprintf(data, "%f", FLAME_environment_variable_inflation_target);
		fputs(data, file);
		fputs("</inflation_target>\n", file);
			fputs("<firms_minimum_equity_ratio>", file);
		sprintf(data, "%f", FLAME_environment_variable_firms_minimum_equity_ratio);
		fputs(data, file);
		fputs("</firms_minimum_equity_ratio>\n", file);
			fputs("<firm_startup_leverage>", file);
		sprintf(data, "%f", FLAME_environment_variable_firm_startup_leverage);
		fputs(data, file);
		fputs("</firm_startup_leverage>\n", file);
			fputs("<household_startup_leverage>", file);
		sprintf(data, "%f", FLAME_environment_variable_household_startup_leverage);
		fputs(data, file);
		fputs("</household_startup_leverage>\n", file);
			fputs("<car_buffer_threshold>", file);
		sprintf(data, "%f", FLAME_environment_variable_car_buffer_threshold);
		fputs(data, file);
		fputs("</car_buffer_threshold>\n", file);
			fputs("<housing_market_entrance_prob>", file);
		sprintf(data, "%f", FLAME_environment_variable_housing_market_entrance_prob);
		fputs(data, file);
		fputs("</housing_market_entrance_prob>\n", file);
			fputs("<fire_sale_threshold>", file);
		sprintf(data, "%f", FLAME_environment_variable_fire_sale_threshold);
		fputs(data, file);
		fputs("</fire_sale_threshold>\n", file);
			fputs("<household_budget_constraint>", file);
		sprintf(data, "%f", FLAME_environment_variable_household_budget_constraint);
		fputs(data, file);
		fputs("</household_budget_constraint>\n", file);
			fputs("<capital_adequecy_ratio>", file);
		sprintf(data, "%f", FLAME_environment_variable_capital_adequecy_ratio);
		fputs(data, file);
		fputs("</capital_adequecy_ratio>\n", file);
			fputs("<housing_price_up_rate>", file);
		sprintf(data, "%f", FLAME_environment_variable_housing_price_up_rate);
		fputs(data, file);
		fputs("</housing_price_up_rate>\n", file);
			fputs("<housing_price_down_rate>", file);
		sprintf(data, "%f", FLAME_environment_variable_housing_price_down_rate);
		fputs(data, file);
		fputs("</housing_price_down_rate>\n", file);
			fputs("<household_mortgage_writeoff_high>", file);
		sprintf(data, "%f", FLAME_environment_variable_household_mortgage_writeoff_high);
		fputs(data, file);
		fputs("</household_mortgage_writeoff_high>\n", file);
			fputs("<household_mortgage_writeoff_low>", file);
		sprintf(data, "%f", FLAME_environment_variable_household_mortgage_writeoff_low);
		fputs(data, file);
		fputs("</household_mortgage_writeoff_low>\n", file);
			fputs("</environment>\n" , file);
	}
	
	
	if(FLAME_integer_in_array(0, output_types, output_type_size) || FLAME_integer_in_array(1, output_types, output_type_size))
	{
		current_xmachine_firm_holder = firm_start_state->agents;
			while(current_xmachine_firm_holder)
			{
				write_firm_agent(file, current_xmachine_firm_holder->agent);

				current_xmachine_firm_holder = current_xmachine_firm_holder->next;
			}
	}
	
	if(FLAME_integer_in_array(0, output_types, output_type_size) || FLAME_integer_in_array(2, output_types, output_type_size))
	{
		current_xmachine_household_holder = household_start_state->agents;
			while(current_xmachine_household_holder)
			{
				write_household_agent(file, current_xmachine_household_holder->agent);

				current_xmachine_household_holder = current_xmachine_household_holder->next;
			}
	}
	
	if(FLAME_integer_in_array(0, output_types, output_type_size) || FLAME_integer_in_array(3, output_types, output_type_size))
	{
		current_xmachine_equityfund_holder = equityfund_start_state->agents;
			while(current_xmachine_equityfund_holder)
			{
				write_equityfund_agent(file, current_xmachine_equityfund_holder->agent);

				current_xmachine_equityfund_holder = current_xmachine_equityfund_holder->next;
			}
	}
	
	if(FLAME_integer_in_array(0, output_types, output_type_size) || FLAME_integer_in_array(4, output_types, output_type_size))
	{
		current_xmachine_bank_holder = bank_start_state->agents;
			while(current_xmachine_bank_holder)
			{
				write_bank_agent(file, current_xmachine_bank_holder->agent);

				current_xmachine_bank_holder = current_xmachine_bank_holder->next;
			}
	}
	
	if(FLAME_integer_in_array(0, output_types, output_type_size) || FLAME_integer_in_array(5, output_types, output_type_size))
	{
		current_xmachine_government_holder = government_start_state->agents;
			while(current_xmachine_government_holder)
			{
				write_government_agent(file, current_xmachine_government_holder->agent);

				current_xmachine_government_holder = current_xmachine_government_holder->next;
			}
	}
	
	if(FLAME_integer_in_array(0, output_types, output_type_size) || FLAME_integer_in_array(6, output_types, output_type_size))
	{
		current_xmachine_centralbank_holder = centralbank_start_state->agents;
			while(current_xmachine_centralbank_holder)
			{
				write_centralbank_agent(file, current_xmachine_centralbank_holder->agent);

				current_xmachine_centralbank_holder = current_xmachine_centralbank_holder->next;
			}
	}
	
	if(FLAME_integer_in_array(0, output_types, output_type_size) || FLAME_integer_in_array(7, output_types, output_type_size))
	{
		current_xmachine_jpoffice_holder = jpoffice_start_state->agents;
			while(current_xmachine_jpoffice_holder)
			{
				write_jpoffice_agent(file, current_xmachine_jpoffice_holder->agent);

				current_xmachine_jpoffice_holder = current_xmachine_jpoffice_holder->next;
			}
	}
	
	if(FLAME_integer_in_array(0, output_types, output_type_size) || FLAME_integer_in_array(8, output_types, output_type_size))
	{
		current_xmachine_mall_holder = mall_start_state->agents;
			while(current_xmachine_mall_holder)
			{
				write_mall_agent(file, current_xmachine_mall_holder->agent);

				current_xmachine_mall_holder = current_xmachine_mall_holder->next;
			}
	}
	
	if(FLAME_integer_in_array(0, output_types, output_type_size) || FLAME_integer_in_array(9, output_types, output_type_size))
	{
		current_xmachine_reagency_holder = reagency_start_state->agents;
			while(current_xmachine_reagency_holder)
			{
				write_reagency_agent(file, current_xmachine_reagency_holder->agent);

				current_xmachine_reagency_holder = current_xmachine_reagency_holder->next;
			}
	}
	
	fputs("</states>\n" , file);

	/* Close the file */
	(void)fclose(file);
}

/** \fn void saveiterationdata(int iteration_number)
 * \brief Save X-machine memory to a file.
 * \param iteration_number The current iteration number.
 */
void saveiterationdata(int iteration_number)
{
	FLAME_output * current_FLAME_output;
	FLAME_output * current_FLAME_output2;
	int output_types[1000];
	int output_type_size = 0;

	/* For each output */
	for(current_FLAME_output = FLAME_outputs; current_FLAME_output != NULL; current_FLAME_output = current_FLAME_output->next)
	{
		/* If period/phase equates to current iteration */
		if(iteration_number%current_FLAME_output->period == current_FLAME_output->phase)
		{
			/* If output has already been handled */
			if(current_FLAME_output->flag == 0)
			{
				/* Check snapshot */
				if(current_FLAME_output->type == 0)
				{
					//snapshot_location = current_FLAME_output->location;
					output_types[0] = 0;
					FLAME_write_xml(current_FLAME_output->location, iteration_number, output_types, 1);
					/* Set flag to 1 and every output to same location */
					current_FLAME_output->flag = 1;
					for(current_FLAME_output2 = FLAME_outputs; current_FLAME_output2 != NULL; current_FLAME_output2 = current_FLAME_output2->next)
					{
						if(strcmp(current_FLAME_output->location, current_FLAME_output2->location) == 0)
						{
							current_FLAME_output2->flag = 1;
						}
					}
				}
				if(current_FLAME_output->type == 1)
				{
					/* Reinitialise agent size */
					output_type_size = 0;
					output_types[0] = 1;
					
					current_FLAME_output->flag = 1;
					for(current_FLAME_output2 = FLAME_outputs; current_FLAME_output2 != NULL; current_FLAME_output2 = current_FLAME_output2->next)
					{
						if(current_FLAME_output2->flag == 0 && strcmp(current_FLAME_output->location, current_FLAME_output2->location) == 0)
						{
							output_types[++output_type_size] = current_FLAME_output2->type;
							
							current_FLAME_output2->flag = 1;
						}
					}
					
					FLAME_write_xml(current_FLAME_output->location, iteration_number, output_types, output_type_size);
				}if(current_FLAME_output->type == 2)
				{
					/* Reinitialise agent size */
					output_type_size = 0;
					output_types[0] = 2;
					
					current_FLAME_output->flag = 1;
					for(current_FLAME_output2 = FLAME_outputs; current_FLAME_output2 != NULL; current_FLAME_output2 = current_FLAME_output2->next)
					{
						if(current_FLAME_output2->flag == 0 && strcmp(current_FLAME_output->location, current_FLAME_output2->location) == 0)
						{
							output_types[++output_type_size] = current_FLAME_output2->type;
							
							current_FLAME_output2->flag = 1;
						}
					}
					
					FLAME_write_xml(current_FLAME_output->location, iteration_number, output_types, output_type_size);
				}if(current_FLAME_output->type == 3)
				{
					/* Reinitialise agent size */
					output_type_size = 0;
					output_types[0] = 3;
					
					current_FLAME_output->flag = 1;
					for(current_FLAME_output2 = FLAME_outputs; current_FLAME_output2 != NULL; current_FLAME_output2 = current_FLAME_output2->next)
					{
						if(current_FLAME_output2->flag == 0 && strcmp(current_FLAME_output->location, current_FLAME_output2->location) == 0)
						{
							output_types[++output_type_size] = current_FLAME_output2->type;
							
							current_FLAME_output2->flag = 1;
						}
					}
					
					FLAME_write_xml(current_FLAME_output->location, iteration_number, output_types, output_type_size);
				}if(current_FLAME_output->type == 4)
				{
					/* Reinitialise agent size */
					output_type_size = 0;
					output_types[0] = 4;
					
					current_FLAME_output->flag = 1;
					for(current_FLAME_output2 = FLAME_outputs; current_FLAME_output2 != NULL; current_FLAME_output2 = current_FLAME_output2->next)
					{
						if(current_FLAME_output2->flag == 0 && strcmp(current_FLAME_output->location, current_FLAME_output2->location) == 0)
						{
							output_types[++output_type_size] = current_FLAME_output2->type;
							
							current_FLAME_output2->flag = 1;
						}
					}
					
					FLAME_write_xml(current_FLAME_output->location, iteration_number, output_types, output_type_size);
				}if(current_FLAME_output->type == 5)
				{
					/* Reinitialise agent size */
					output_type_size = 0;
					output_types[0] = 5;
					
					current_FLAME_output->flag = 1;
					for(current_FLAME_output2 = FLAME_outputs; current_FLAME_output2 != NULL; current_FLAME_output2 = current_FLAME_output2->next)
					{
						if(current_FLAME_output2->flag == 0 && strcmp(current_FLAME_output->location, current_FLAME_output2->location) == 0)
						{
							output_types[++output_type_size] = current_FLAME_output2->type;
							
							current_FLAME_output2->flag = 1;
						}
					}
					
					FLAME_write_xml(current_FLAME_output->location, iteration_number, output_types, output_type_size);
				}if(current_FLAME_output->type == 6)
				{
					/* Reinitialise agent size */
					output_type_size = 0;
					output_types[0] = 6;
					
					current_FLAME_output->flag = 1;
					for(current_FLAME_output2 = FLAME_outputs; current_FLAME_output2 != NULL; current_FLAME_output2 = current_FLAME_output2->next)
					{
						if(current_FLAME_output2->flag == 0 && strcmp(current_FLAME_output->location, current_FLAME_output2->location) == 0)
						{
							output_types[++output_type_size] = current_FLAME_output2->type;
							
							current_FLAME_output2->flag = 1;
						}
					}
					
					FLAME_write_xml(current_FLAME_output->location, iteration_number, output_types, output_type_size);
				}if(current_FLAME_output->type == 7)
				{
					/* Reinitialise agent size */
					output_type_size = 0;
					output_types[0] = 7;
					
					current_FLAME_output->flag = 1;
					for(current_FLAME_output2 = FLAME_outputs; current_FLAME_output2 != NULL; current_FLAME_output2 = current_FLAME_output2->next)
					{
						if(current_FLAME_output2->flag == 0 && strcmp(current_FLAME_output->location, current_FLAME_output2->location) == 0)
						{
							output_types[++output_type_size] = current_FLAME_output2->type;
							
							current_FLAME_output2->flag = 1;
						}
					}
					
					FLAME_write_xml(current_FLAME_output->location, iteration_number, output_types, output_type_size);
				}if(current_FLAME_output->type == 8)
				{
					/* Reinitialise agent size */
					output_type_size = 0;
					output_types[0] = 8;
					
					current_FLAME_output->flag = 1;
					for(current_FLAME_output2 = FLAME_outputs; current_FLAME_output2 != NULL; current_FLAME_output2 = current_FLAME_output2->next)
					{
						if(current_FLAME_output2->flag == 0 && strcmp(current_FLAME_output->location, current_FLAME_output2->location) == 0)
						{
							output_types[++output_type_size] = current_FLAME_output2->type;
							
							current_FLAME_output2->flag = 1;
						}
					}
					
					FLAME_write_xml(current_FLAME_output->location, iteration_number, output_types, output_type_size);
				}if(current_FLAME_output->type == 9)
				{
					/* Reinitialise agent size */
					output_type_size = 0;
					output_types[0] = 9;
					
					current_FLAME_output->flag = 1;
					for(current_FLAME_output2 = FLAME_outputs; current_FLAME_output2 != NULL; current_FLAME_output2 = current_FLAME_output2->next)
					{
						if(current_FLAME_output2->flag == 0 && strcmp(current_FLAME_output->location, current_FLAME_output2->location) == 0)
						{
							output_types[++output_type_size] = current_FLAME_output2->type;
							
							current_FLAME_output2->flag = 1;
						}
					}
					
					FLAME_write_xml(current_FLAME_output->location, iteration_number, output_types, output_type_size);
				}
			}
		}
	}
	/* Set flags back to 0 */
	for(current_FLAME_output = FLAME_outputs; current_FLAME_output != NULL; current_FLAME_output = current_FLAME_output->next)
	{
		current_FLAME_output->flag = 0;
	}
}
