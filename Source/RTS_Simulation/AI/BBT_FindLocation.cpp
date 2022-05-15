// Fill out your copyright notice in the Description page of Project Settings.


#include "BBT_FindLocation.h"


EBTNodeResult::Type UBBT_FindLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

	
	FinishExecute(true);
	return Super::ExecuteTask(OwnerComp, NodeMemory);
}
