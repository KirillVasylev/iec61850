/*
 * ASN_Type.h
 *
 *  Created on: 02.10.2012
 *      Author: kv
 */

#ifndef ASN_TYPE_H_
#define ASN_TYPE_H_


typedef union
{
  unsigned int Int;
  unsigned char Char[2];
} AST_Int;

typedef enum
{
  initiate_RequestPDU = 0xA8,
  initiate_ResponsePDU = 0xA9,
  confirmed_RequestPDU = 0xA0,
  confirmed_ResponsePDU = 0xA1,
  unconfirmedPDU = 0xA3,
  confirmed_ErrorPDU = 0xA2

} ASN_Identifier;

typedef enum
{
  Bollean = 0x1,
  integer = 0x2,
  BitString = 0x3,
  OtcetString = 0x4,
  Null = 0x5,
  ObjectIdentifier = 0x6,
  Sequense = 0x10,
  IA5String = 0x16,
  UTCTime = 0x17,
  GeneralizeTime = 0x18,
  VisibleString = 0x1A
} ASN_Type;

typedef enum
{
  object_invalidated = 0x0,
  hardware_fault = 0x1,
  temporarily_unavailable = 0x2,
  object_access_denied = 0x3,
  object_undefined = 0x4,
  invalid_address = 0x5,
  type_unsupported = 0x6,
  type_inconsistent = 0x7,
  object_attribute_inconsistent = 0x8,
  object_access_unsupported = 0x9,
  object_non_existent = 0xA

} ASN_Error;

typedef union
{
  struct
  {
    unsigned char array_support : 1;
    unsigned char structure_support:1;
    unsigned char named_variable_support:1;
    unsigned char unamed_variable_support:1;
    unsigned char scattered_access_support:1;
    unsigned char third_party_operations_support:1;
    unsigned char named_variable_list_support:1;
    unsigned char ASN_real_data_type_support:1;
    unsigned char acknowledge_event_condition_support:1;
    unsigned char condition_event_support:1;

  } Bit;
  unsigned char Char[2];
}ASN_Param;

typedef union
{
  typedef struct
  {//Add service support;
    unsigned char staus:1;
  }Bit;
  unsigned char Char[22];
}ASN_Services;



#endif /* ASN_TYPE_H_ */
