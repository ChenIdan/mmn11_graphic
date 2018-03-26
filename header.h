/*
 * header.h
 *
 *  Created on: Mar 17, 2018
 *      Author: chen
 */

#ifndef HEADER_H_
#define HEADER_H_



#endif /* HEADER_H_ */

typedef struct string{
	/*location of the first character in string*/
	float x;
	float y;

	/*width and heigh of the string box*/
	float box_w;
	float box_h;

	char *str;
}str_box;

typedef struct button{
	float x;
	float y; /*button location*/

	float w;
	float h;

	str_box str;
}Button;
