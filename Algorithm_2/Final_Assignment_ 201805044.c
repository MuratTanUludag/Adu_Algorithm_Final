#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
/*	Declare a structre that is named "product" then fulfill these conditions:
	1.Add product
	2.Update Product
	3.Search for Product
	4.Increase quantity
	5.Decrease quantity
	6.List all products
	7.Exit
*/
// Define a struct to hold product information
struct Product {
    int id;
    char name[50];
    char unit[50];
    int quantity;
};

int main() {
	int input=0;
	char input_name[50];
	int counter,counter2,Id_num=0;
    struct Product products[100]; // Array of products
    int num_products = 0; // Number of products currently in the array
    FILE *fp; // Pointer to file
    char filename[] = "products.txt"; // Name of file containing product information
    char line[200]; // Buffer for reading each line of the file
    char *token; // Pointer to token within line
    int i;

    // Open file for reading
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        return 1;
    }
    // Read each line of file, parse product information, and store in array
    while (fgets(line, 100, fp) != NULL) {
   		token = strtok(line, ",");
   		products[num_products].id=atoi(token);
    	token = strtok(NULL, ",");
    	strcpy(products[num_products].name, token);
  		token = strtok(NULL, ",");
    	strcpy(products[num_products].unit, token);
		token = strtok(NULL, ",");
        products[num_products].quantity=atoi(token);
        token = strtok(NULL, ",");
        //printf("%d\t,%s\t,%s\t,%d\n",products[num_products].id,products[num_products].name, products[num_products].unit, products[num_products].quantity);
        num_products++;
   		}
    
    while(true){
    	printf("Menu:\n1. Add product\n2. Update a product with name\n3. Search  for a product\n4. Increase quantity of a product\n5. Decrease quantity of a product\n6. List all products\n7. Exit\n\nEnter your choice(1-7):");
    	scanf("%d",&input);
    	while ((getchar()) != '\n');
    	switch (input) {
        	case 1:
        		counter=0;
        		while (counter!=1){	
        			printf("Enter product id: ");
        			counter=scanf("%d", &input);
    				products[num_products].id=input;
    				while ((getchar()) != '\n');
				}
				printf("Enter product name: ");
        		scanf("%s", &products[num_products].name);
    			while ((getchar()) != '\n');
        		printf("Enter quantity: ");
        		scanf("%s", &products[num_products].unit);
    			while ((getchar()) != '\n');
    			counter=0;
				while (counter!=1){	
        			printf("Enter price: ");
        			counter=scanf("%d", &input);
    				products[num_products].quantity=input;
    				while ((getchar()) != '\n');
				}
    			printf("product is insterted successfully\n");
				num_products++;
				break;
    	    case 2:
    	    	printf("Enter product number to update: %d products found. Which field you want to update? ",num_products);
    			scanf("%d",&Id_num);			
    			printf("1.Id\n2.Name\n3.Quantity\n4.Price\n");
    			printf("Enter your choice(1-7): ");
    			scanf("%d",&input);
    			while ((getchar()) != '\n');
    			switch (input) {
    				case 1:
        				printf("Enter new id: ");
        				scanf("%d", &input);
        				while ((getchar()) != '\n');
    					for (counter = 0; counter < 100; counter++) {
        					if (products[counter].id == Id_num) {
            				products[counter].id = input;
            				break;
        					}
    					}
    					break;
    				case 2:
						printf("Enter new name: ");
        				scanf("%s", &input_name);
        				while ((getchar()) != '\n');
    					for (counter = 0; counter < 100; counter++) {
        					if (products[counter].id == Id_num) {
        						for(counter2=0;counter2<50;counter2++){
        							products[counter].name[counter2] = input_name[counter2];
								}
            				break;
        					}
    					}
    					break;
    				case 3:				
        				printf("Enter new unit: ");
        				scanf("%s", &input_name);
        				while ((getchar()) != '\n');
    					for (counter = 0; counter < 100; counter++) {
        					if (products[counter].id == Id_num) {
        						for(counter2=0;counter2<50;counter2++){
        							products[counter].unit[counter2] = input_name[counter2];
								}
            				break;
        					}
    					}
    					break;
    				case 4:
        				printf("Enter new price: ");
        				scanf("%d", &input);
        				while ((getchar()) != '\n');
    					for (counter = 0; counter < 100; counter++) {
        					if (products[counter].id == Id_num) {
            				products[counter].quantity = input;
            				break;
        					}
    					}
    				printf("product is updated successfully\n");
    					break;
    				default:
    					printf("Error: Update failed\n");
				}
				break;
       		case 3:
       			printf("Enter name of the product: ");
       			scanf("%49[^\n]",&input_name); //s1 is char [50]
    			Id_num=0;
       			for (counter = 0; counter < num_products; counter++) {
       				if (strcmp(products[counter].name, input_name) == 0) {
            			printf("%d\t%s\t%s\t%d\n",products[counter].id,products[counter].name, products[counter].unit, products[counter].quantity);
        			}
				}
				break;
       		case 4:
       			printf("Enter product number to update: ");
       			scanf("%d",&Id_num);
       			printf("Enter the increment quantity: ");
       			scanf("%d",&input);
       			for (counter = 0; counter < 100; counter++) {
        			if (products[counter].id == Id_num) {
            			products[counter].quantity = input + products[counter].quantity ;
            			counter2= counter;
            			break;
        			}
    			}
    			printf("\n\nNew quantity of %s = %d\n",products[counter2].name,products[counter2].quantity);
				break;
        	case 5:
        		printf("Enter product number to update: ");
       			scanf("%d",&Id_num);
       			printf("Enter the decrement quantity: ");
       			scanf("%d",&input);
       			for (counter = 0; counter < 100; counter++) {
        			if (products[counter].id == Id_num) {
            			products[counter].quantity = products[counter].quantity -input;
            			counter2= counter;
            			break;
        			}
    			}
    			printf("\n\nNew quantity of %s = %d\n",products[counter2].name,products[counter2].quantity);
        	    break;
        	case 6:
        		printf("%10s%30s%20s%20s\n","ID","Name", "Unit", "Quantity");
        		for(counter=0;counter<num_products;counter++){
        			printf("%10d%30s%20s%20d\n",products[counter].id,products[counter].name, products[counter].unit, products[counter].quantity);
				}
        	    break;
        	case 7:
        		break;
       		default:
        		printf("Error: Input is inadequate\n");
         		break;
    		}
    	if(input==7){
    		break;
		}
	}
    	
	
    
    // Close file
    fclose(fp);
}
