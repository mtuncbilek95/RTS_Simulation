// Fill out your copyright notice in the Description page of Project Settings.


#include "RTS_Controller.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "RTS_CameraPawn.h"

void ARTS_Controller::MoveForward(float Value) const
{
	const FVector ActorLocation = GetPawn()->GetActorLocation();
	const FVector PushedLocation = FVector(Value*MovementSpeed, 0,0);

	GetPawn()->SetActorLocation(ActorLocation+PushedLocation,false,nullptr);
}

void ARTS_Controller::MoveRight(float Value) const
{
	const FVector ActorLocation = GetPawn()->GetActorLocation();
	const FVector PushedLocation = FVector(0, Value * MovementSpeed,0);
	GetPawn()->SetActorLocation(ActorLocation+PushedLocation,false,nullptr);
}

void ARTS_Controller::Zoom(float Value) const
{
	const ARTS_CameraPawn* CameraPawn = Cast<ARTS_CameraPawn>(GetPawn());

	CameraPawn->SpringArm->TargetArmLength = UKismetMathLibrary::FInterpTo(CameraPawn->SpringArm->TargetArmLength,
		CameraPawn->SpringArm->TargetArmLength+Value*MovementSpeed*3, GetWorld()->DeltaTimeSeconds, 10);
}