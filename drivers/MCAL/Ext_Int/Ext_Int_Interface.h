#ifndef EX_INT_INTERFACE_H_
#define EX_INT_INTERFACE_H_

typedef enum{
	EXTI0=0,
	EXTI1,
	EXTI2
}EXTI_SOURCE;

typedef enum{
	EXTI_RISING_EDGE=0,
	EXTI_FALLING_EDGE,
	EXTI_LOW_LEVEL,
	EXTI_ANY_LOGICAL_CHANGE
}TRIGGER_SOURCE;


void EXTI_Enable(EXTI_SOURCE Int_source,TRIGGER_SOURCE trg_source);
void EXTI_Disable(EXTI_SOURCE Int_source);
void EXTI2_SetCallBack (void (*p2f_var) (void));


#endif /* EX_INT_H_ */
