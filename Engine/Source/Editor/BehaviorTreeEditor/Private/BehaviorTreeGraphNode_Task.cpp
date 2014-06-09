// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "BehaviorTreeEditorPrivatePCH.h"

UBehaviorTreeGraphNode_Task::UBehaviorTreeGraphNode_Task(const class FPostConstructInitializeProperties& PCIP) : Super(PCIP)
{
}

void UBehaviorTreeGraphNode_Task::AllocateDefaultPins()
{
	CreatePin(EGPD_Input, UBehaviorTreeEditorTypes::PinCategory_SingleComposite, TEXT(""), NULL, false, false, TEXT("In"));
}

FText UBehaviorTreeGraphNode_Task::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	const UBTNode* MyNode = Cast<UBTNode>(NodeInstance);
	if (MyNode != NULL)
	{
		return FText::FromString(MyNode->GetNodeName());
	}
	else if (!ClassData.GetClassName().IsEmpty())
	{
		return NSLOCTEXT("BehaviorTreeGraphNode", "UnknownNodeClass", "Can't load class!");
	}

	return Super::GetNodeTitle(TitleType);
}

FName UBehaviorTreeGraphNode_Task::GetNameIcon() const
{
	return FName("BTEditor.Graph.BTNode.Task.Icon");
}

void UBehaviorTreeGraphNode_Task::GetContextMenuActions(const FGraphNodeContextMenuBuilder& Context) const
{
	AddContextMenuActionsDecorators(Context);
}
