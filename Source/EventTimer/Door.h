// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Engine/Classes/Components/StaticMeshComponent.h>
#include "Door.generated.h"

UCLASS()
class EVENTTIMER_API ADoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* DoorMesh;
	// 문 모델링 메시를 가지는 변수 선언

	UPROPERTY(EditAnywhere)
	float CloseTime;
	// 문이 열렸다가 닫히는 시간을 표시할 변수 선언

	float DoorDeltaTime;
	// 문이 열리고 닫히는 과정을 표현하는데 사용할 변수 선언

	bool bOpen;
	// 문이 열린 상태인지 표현할 bool 타입 변수 선언 

	FTimerHandle DoorTimerHandle;
	// 타이머를 관리하는데 쓰일 핸들타입의 변수 선언

	FRotator OriginRotation;
	// 문의 원래 상태를 저장하고 있을 FRotator 타입의 변수 선언(회전)

	void Open();

	void Close();
	// 문을 열고 닫는 동작을 구현할 Open, Close 함수 선언	
};
