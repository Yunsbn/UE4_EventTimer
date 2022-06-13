// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"

// Sets default values
ADoor::ADoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door Mesh"));
	RootComponent = DoorMesh;

	CloseTime = 3.0f;

}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();

	OriginRotation = GetActorRotation();
	GetWorldTimerManager().SetTimer(DoorTimerHandle, this, &ADoor::Open, 0.03f, true);
	
}

// Called every frame
void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	DoorDeltaTime += DeltaTime;
}

void ADoor::Open()
{
	if (!bOpen)
	{
		bOpen = true;
		DoorDeltaTime = 0.0f;
		// 문이 열리지 않은 상태라면 열린 상태로 만들며 DoorDeltaTime을 0으로 만듬
	}

	FRotator rotation = GetActorRotation();
	// 액터의 회전 상태를 가져옴
	rotation = OriginRotation + FRotator(0.0f, FMath::Lerp(0.0f, 90.0f, DoorDeltaTime), 0.0f);
	SetActorRotation(rotation);
	// DoorDeltaTime 값의 상태에 따라 열린 상태로 문 회전
	
	if (DoorDeltaTime > 1.0f) 
	{
		GetWorldTimerManager().ClearTimer(DoorTimerHandle);
		GetWorldTimerManager().SetTimer(DoorTimerHandle, this, &ADoor::Close, 0.03f, true, CloseTime);
		// DoorDeltaTime의 값이 1보다 커지면 현재 작동중인 타이머를 멈춘 다음 문을 닫는 처리를 진행하는 Close 함수를 호출하는 타이머를 CloseTime이 지난 후에 동작하도록 만듦
	}
}

void ADoor::Close()
{
	if (bOpen)
	{
		bOpen = false;
		DoorDeltaTime = 0.0f;
	}

	FRotator rotation = GetActorRotation();
	rotation = OriginRotation + FRotator(0.0f, FMath::Lerp(90.0f, 0.0f, DoorDeltaTime), 0.0f);
	SetActorRotation(rotation);
	
	if (DoorDeltaTime > 1.0f)
	{
		GetWorldTimerManager().ClearTimer(DoorTimerHandle);
	}
}
