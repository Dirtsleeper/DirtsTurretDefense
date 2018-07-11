// Fill out your copyright notice in the Description page of Project Settings.

#include "TD_Widget.h"

#include "Animation/WidgetAnimation.h"

void UTD_Widget::Open(bool bFadeIn)
{
	if (bFadeIn && m_bRequiresFadeAnimation && _FadeAnimationPtr)
	{
		FadeIn();
	}
	else
	{
		SetVisibility(ESlateVisibility::SelfHitTestInvisible);
	}
}

void UTD_Widget::Close(bool bFadeOut)
{
	if (bFadeOut && m_bRequiresFadeAnimation && _FadeAnimationPtr)
	{
		FadeOut();
	}
	else
	{
		SetVisibility(ESlateVisibility::Collapsed);
	}
}

void UTD_Widget::FadeIn()
{
	PreFadeIn();
	_FadeAnimationPtr->OnAnimationFinished.AddDynamic(this, &UTD_Widget::PostFadeIn);
	PlayAnimation(_FadeAnimationPtr);
}

void UTD_Widget::NativeConstruct()
{
	Super::NativeConstruct();

	if (m_bRequiresFadeAnimation)
	{
		StoreFadeAnimation();
	}

	if (!BindButtons())
	{
		UE_LOG(LogTemp, Error, TEXT("%s failed to bind a button."), *GetFName().ToString());
	}
}

void UTD_Widget::PreFadeIn()
{
	SetVisibility(ESlateVisibility::SelfHitTestInvisible);
}

void UTD_Widget::PostFadeIn()
{
	_FadeAnimationPtr->OnAnimationFinished.RemoveDynamic(this, &UTD_Widget::PostFadeIn);
}

void UTD_Widget::FadeOut()
{
	PreFadeOut();
	_FadeAnimationPtr->OnAnimationFinished.AddDynamic(this, &UTD_Widget::PostFadeOut);
	PlayAnimation(_FadeAnimationPtr, 0.f, 1, EUMGSequencePlayMode::Reverse);
}

//https://answers.unrealengine.com/questions/427948/get-widget-animation-in-c.html
void UTD_Widget::StoreFadeAnimation()
{
	UProperty* prop = GetClass()->PropertyLink;

	// Run through all properties of this class to find any widget animations
	while (prop != nullptr)
	{
		// Only interested in object properties
		if (prop->GetClass() == UObjectProperty::StaticClass())
		{
			UObjectProperty* objectProp = Cast<UObjectProperty>(prop);

			// Only want the properties that are widget animations
			if (objectProp->PropertyClass == UWidgetAnimation::StaticClass())
			{
				UObject* object = objectProp->GetObjectPropertyValue_InContainer(this);

				UWidgetAnimation* widgetAnim = Cast<UWidgetAnimation>(object);

				if (widgetAnim && widgetAnim->GetFName() == TEXT("FadeAnimation_INST"))
				{
					_FadeAnimationPtr = widgetAnim;
				}
			}
		}

		prop = prop->PropertyLinkNext;
	}
	if (_FadeAnimationPtr == nullptr && m_bRequiresFadeAnimation)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s is missing Fade Animation. If this widget does not need a fade animation, set bRequiresFadeAnimation to false."), *GetFName().ToString());
	}
}

void UTD_Widget::PreFadeOut()
{

}

void UTD_Widget::PostFadeOut()
{
	_FadeAnimationPtr->OnAnimationFinished.RemoveDynamic(this, &UTD_Widget::PostFadeOut);
	SetVisibility(ESlateVisibility::Collapsed);
}

bool UTD_Widget::BindButtons()
{
	return true;
}
