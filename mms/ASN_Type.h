/*
 * ASN_Type.h
 *
 *  Created on: 02.10.2012
 *      Author: kv
 */

#ifndef ASN_TYPE_H_
#define ASN_TYPE_H_

typedef union {
	unsigned int Int;
	unsigned char Char[2];
} AST_Int;

typedef enum {
	initiate_RequestPDU = 0xA8,
	initiate_ResponsePDU = 0xA9,
	confirmed_RequestPDU = 0xA0,
	confirmed_ResponsePDU = 0xA1,
	unconfirmedPDU = 0xA3,
	confirmed_ErrorPDU = 0xA2

} ASN_Identifier;

typedef enum
{
	LocalDetailCalled=0x80,
    negociatedMaxServOutstandingCalling=0x81,	
    negociatedMaxServOutstandingCalled	=0x82,
    negociatedDataStructureNestingLevel		=0x83,	
    mmsInitResponseDetail=0xA4
}ASN_Initiate_PDU;

typedef enum
{
	ProposedVersionNumber=0x80,
	ProposedParam=0x81,
	ProposedServices=0x82
}ASN_mmsInitDetail;

typedef enum
{
	InnvokeID=0x02,
	serviceReadRequest=0xA4,
	serviceWriteRequest=0XA5,
	serviceReadResponse=0xA4,
	serviceWriteResponse=0xA5
}ASN_Confirmed_Sevice;

typedef enum
{
	List =0xA0,
	List_ofVariableItem = 0x30,
	Name = 0xA1,

}ASN_Service_Byte;

typedef enum {
	Bollean = 0x1,
	Integer = 0x2,
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



typedef enum {
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

typedef union {
	struct {
		unsigned char array_support :1;
		unsigned char structure_support :1;
		unsigned char named_variable_support :1;
		unsigned char unamed_variable_support :1;
		unsigned char scattered_access_support :1;
		unsigned char third_party_operations_support :1;
		unsigned char named_variable_list_support :1;
		unsigned char ASN_real_data_type_support :1;
		unsigned char acknowledge_event_condition_support :1;
		unsigned char condition_event_support :1;

	} Bit;
	unsigned char Char[2];
} ASN_Param;

typedef union {
	typedef struct { //Add service support;
		unsigned char status :1;
		unsigned char getNameList :1;
		unsigned char identify :1;
		unsigned char rename :1;
		unsigned char read :1;
		unsigned char write :1;
		unsigned char getVariableAccessAttributes :1;
		unsigned char defineNamedVariable :1;
		unsigned char defineScatteredAccess :1;	// bit 8 is reserved for use of a service defined in annex E
		unsigned char getScatteredAccessAttributes :1; //bit 9 is reserved for use of a service defined in annex E
		unsigned char deleteVariableAccess :1;
		unsigned char defineNamedVariableList1;
		unsigned char getNamedVariableListAttributes :1;
		unsigned char deleteNamedVariableList :1;
		unsigned char defineNamedType :1;
		unsigned char getNamedTypeAttributes :1;
		unsigned char deleteNamedType :1;
		unsigned char input :1;
		unsigned char output :1;
		unsigned char takeControl :1;
		unsigned char relinquishControl :1;
		unsigned char defineSemaphore :1;
		unsigned char deleteSemaphore :1;
		unsigned char reportSemaphoreStatus :1;
		unsigned char reportPoolSemaphoreStatus :1;
		unsigned char reportSemaphoreEntryStatus :1;
		unsigned char initiateDownloadSequence :1;
		unsigned char downloadSegment :1;
		unsigned char terminateDownloadSequence :1;
		unsigned char initiateUploadSequence :1;
		unsigned char uploadSegment :1;
		unsigned char terminateUploadSequence :1;
		unsigned char requestDomainDownload :1;
		unsigned char requestDomainUpload :1;
		unsigned char loadDomainContent :1;
		unsigned char storeDomainContent :1;
		unsigned char deleteDomain :1;
		unsigned char getDomainAttributes :1;
		unsigned char createProgramInvocation :1;
		unsigned char deleteProgramInvocation :1;
		unsigned char start :1;
		unsigned char stop :1;
		unsigned char resume :1;
		unsigned char reset :1;
		unsigned char kill :1;
		unsigned char getProgramInvocationAttributes :1;
		unsigned char obtainFile :1;
		unsigned char defineEventCondition :1;
		unsigned char deleteEventCondition :1;
		unsigned char getEventConditionAttributes :1;
		unsigned char reportEventConditionStatus :1;
		unsigned char alterEventConditionMonitoring :1;
		unsigned char triggerEvent :1;
		unsigned char defineEventAction :1;
		unsigned char deleteEventAction :1;
		unsigned char getEventActionAttributes :1;
		unsigned char reportEventActionStatus :1;
		unsigned char defineEventEnrollment :1;
		unsigned char deleteEventEnrollment :1;
		unsigned char alterEventEnrollment :1;
		unsigned char reportEventEnrollmentStatus :1;
		unsigned char getEventEnrollmentAttributes :1;
		unsigned char acknowledgeEventNotification :1;
		unsigned char getAlarmSummary :1;
		unsigned char getAlarmEnrollmentSummary :1;
		unsigned char readJournal :1;
		unsigned char writeJournal :1;
		unsigned char initializeJournal :1;
		unsigned char reportJournalStatus :1;
		unsigned char createJournal :1;
		unsigned char deleteJournal :1;
		unsigned char getCapabilityList :1;
		unsigned char fileOpen :1; //-- bit 72 is reserved for use of a service defined in annex D
		unsigned char fileRead :1; //-- bit 73 is reserved for use of a service defined in annex D
		unsigned char fileClose :1; // -- bit 74 is reserved for use of a service defined in annex D
		unsigned char fileRename :1; //-- bit 75 is reserved for use of a service defined in annex D
		unsigned charfileDelete :1; //-- bit 76 is reserved for use of a service defined in annex D
		unsigned charfileDirectory :1; //-- bit 77 is reserved for use of a service defined in annex D
		unsigned char unsolicitedStatus :1;
		unsigned char informationReport :1;
		unsigned char eventNotification :1;
		unsigned char attachToEventCondition :1;
		unsigned char attachToSemaphore :1;
		unsigned char conclude :1;
		unsigned char cancel :1;
		unsigned char getDataExchangeAttributes :1;//-- Shall not appear in minor version one
		unsigned char exchangeData :1; //-- Shall not appear in minor version one
		unsigned char defineAccessControlList :1; //-- Shall not appear in minor version one
		unsigned char getAccessControlListAttributes :1; //-- Shall not appear in minor version one or two			  /
		unsigned char reportAccessControlledObjects :1; //-- Shall not appear in minor version one or two
		unsigned char deleteAccessControlList :1; //-- Shall not appear in minor version one or two
		unsigned charalterAccessControl :1; //-- Shall not appear in minor version one or two
		unsigned char reconfigureProgramInvocation :1; //-- Shall not appear in minor version one or two
	} Bit;
	unsigned char Char[12];
} ASN_Services;

#endif /* ASN_TYPE_H_ */