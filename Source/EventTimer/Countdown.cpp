// Fill out your copyright notice in the Description page of Project Settings.


#include "Countdown.h"

// Sets default values
ACountdown::ACountdown()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	CountdownText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Countdown Text"));
	/* CountdwonText를 초기화 할 때 사용한 CreateDefaultSubobject 함수는
	템플릿인 <> 안에 넣어준 타입의 컴포넌트를 생성해서 반환하는 기능을 함 */

	CountdownText->SetHorizontalAlignment(EHTA_Center);
	// 생성되는 CountdownText를 가운데 정렬해주고
	CountdownText->SetWorldSize(150.0f);
	// 사이즈를 지정

	RootComponent = CountdownText;
	// 이렇게 만든 CountdownText 컴포넌트를 이 액터의 Root Component로 만들어 줌

	CountdownTime = 3;
}

// Called when the game starts or when spawned
void ACountdown::BeginPlay()
{
	Super::BeginPlay();
	
	UpdateTimerDisplay();
	GetWorldTimerManager().SetTimer(CountdownTimerHandle, this, &ACountdown::AdvanceTimer, 1.0f, true);
}

//초기화 작업이 끝난 후 UpdateTimerDisplay 함수를 구현
void ACountdown::UpdateTimerDisplay()
{
	CountdownText->SetText(FString::FromInt(FMath::Max(CountdownTime, 0)));
}

void ACountdown::AdvanceTimer()
{
	--CountdownTime;
	UpdateTimerDisplay();

	if (CountdownTime < 1)
	{
		GetWorldTimerManager().ClearTimer(CountdownTimerHandle);
		CountdownHasFinished();
	}
}
void ACountdown::CountdownHasFinished_Implementation()
{
	CountdownText->SetText(TEXT("GO!"));
}
