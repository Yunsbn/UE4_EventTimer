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
	// ī��Ʈ�ٿ��� �����Ϳ��� ���������� �����ϰ� ����� �� �ִ� ��ũ��

	int32 CountdownTime;
	UTextRenderComponent* CountdownText;

	void UpdateTimerDisplay();

	void AdvanceTimer();
	// Ÿ�̸Ӱ� ���ư��鼭 ȣ��� �Լ�

	UFUNCTION(BlueprintNativeEvent)
	void CountdownHasFinished();
	// AdvanceTimer �Լ��� Ÿ�̸Ӱ� ������ ��ŭ �۵��� �� ������ ó�� �Լ�
	virtual void CountdownHasFinished_Implementation();
	// �� UFUNTION() �� Implementation �Լ��� �����̳ʰ� �������Ʈ�� �Լ��� ����� ������ �� �ְ� ��

	FTimerHandle CountdownTimerHandle;
	// Countdown�� ����ؼ� ���ư��� �ʵ��� �����ϱ� ���� �ʿ�

};
