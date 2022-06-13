// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/Classes/Components/TextRenderComponent.h"
#include "Countdown.generated.h"

UCLASS()
class EVENTTIMER_API ACountdown : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACountdown();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UPROPERTY(EditAnywhere)
	// 카운트다운을 에디터에서 공개적으로 변경하게 사용할 수 있는 매크로

	int32 CountdownTime;
	UTextRenderComponent* CountdownText;

	void UpdateTimerDisplay();

	void AdvanceTimer();
	// 타이머가 돌아가면서 호출될 함수

	UFUNCTION(BlueprintNativeEvent)
	void CountdownHasFinished();
	// AdvanceTimer 함수가 타이머가 지정한 만큼 작동한 뒤 마무리 처리 함수
	virtual void CountdownHasFinished_Implementation();
	// 위 UFUNTION() 과 Implementation 함수로 디자이너가 블루프린트로 함수의 기능을 수정할 수 있게 함

	FTimerHandle CountdownTimerHandle;
	// Countdown이 계속해서 돌아가지 않도록 종료하기 위해 필요

};
