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
	// �� �𵨸� �޽ø� ������ ���� ����

	UPROPERTY(EditAnywhere)
	float CloseTime;
	// ���� ���ȴٰ� ������ �ð��� ǥ���� ���� ����

	float DoorDeltaTime;
	// ���� ������ ������ ������ ǥ���ϴµ� ����� ���� ����

	bool bOpen;
	// ���� ���� �������� ǥ���� bool Ÿ�� ���� ���� 

	FTimerHandle DoorTimerHandle;
	// Ÿ�̸Ӹ� �����ϴµ� ���� �ڵ�Ÿ���� ���� ����

	FRotator OriginRotation;
	// ���� ���� ���¸� �����ϰ� ���� FRotator Ÿ���� ���� ����(ȸ��)

	void Open();

	void Close();
	// ���� ���� �ݴ� ������ ������ Open, Close �Լ� ����	
};
