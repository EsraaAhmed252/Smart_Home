#include "StdTypes.h"
#include "MemMap.h"
#include "UTILS.h"
#include "Routines.h"

#include "Ext_Int/Ext_Int_Interface.h"

static void (*ptr3) (void) = NULL;

void EXTI_Enable(EXTI_SOURCE Int_source,TRIGGER_SOURCE trg_source)
{
	switch (Int_source) {
		case EXTI0:
			switch (trg_source) {
				case EXTI_RISING_EDGE:
					SET_BIT(MCUCR,0);
					SET_BIT(MCUCR,1);
					break;

				case EXTI_FALLING_EDGE:
					CLR_BIT(MCUCR,0);
					SET_BIT(MCUCR,1);
					break;

				case EXTI_LOW_LEVEL:
					CLR_BIT(MCUCR,0);
					CLR_BIT(MCUCR,1);
					break;

				case EXTI_ANY_LOGICAL_CHANGE:
					SET_BIT(MCUCR,0);
					CLR_BIT(MCUCR,1);
					break;

				default:
					break;
			}

				SET_BIT(GICR,6);
			break;
		case EXTI1:
			switch (trg_source) {
				case EXTI_RISING_EDGE:
					SET_BIT(MCUCR,2);
					SET_BIT(MCUCR,3);
					break;

				case EXTI_FALLING_EDGE:
					CLR_BIT(MCUCR,2);
					SET_BIT(MCUCR,3);
					break;

				case EXTI_LOW_LEVEL:
					CLR_BIT(MCUCR,2);
					CLR_BIT(MCUCR,3);
					break;

				case EXTI_ANY_LOGICAL_CHANGE:
					SET_BIT(MCUCR,2);
					CLR_BIT(MCUCR,3);
					break;

				default:
					break;
			}

			SET_BIT(GICR,7);
			break;
		case EXTI2:
			switch (trg_source) {
				case EXTI_RISING_EDGE:
					SET_BIT(MCUCSR,6);
					break;

				case EXTI_FALLING_EDGE:
					CLR_BIT(MCUCSR,6);
					break;

				default:
					break;
			}

			SET_BIT(GICR,5);
			break;

		default:
			break;
		}
}


void EXTI_Disable(EXTI_SOURCE Int_source)
{
	switch (Int_source) {
		case EXTI0:
			CLR_BIT(GICR,6);
			break;
		case EXTI1:
			CLR_BIT(GICR,7);
			break;
		case EXTI2:
			CLR_BIT(GICR,5);
			break;
		default:
			break;
	}
}

void EXTI2_SetCallBack (void (*p2f_var) (void))
{
	ptr3 = p2f_var ;
}

ISR(INT2_vect){
	if(ptr3 != NULL)
	ptr3();
}

