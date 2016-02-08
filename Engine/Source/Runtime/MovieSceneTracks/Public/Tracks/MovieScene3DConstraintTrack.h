// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "MovieSceneNameableTrack.h"
#include "MovieScene3DConstraintTrack.generated.h"


class UMovieSceneSection;


/**
 * Base class for constraint tracks (tracks that are dependent upon other objects).
 */
UCLASS( MinimalAPI )
class UMovieScene3DConstraintTrack
	: public UMovieSceneNameableTrack
{
	GENERATED_UCLASS_BODY()

public:

	/**
	 * Adds a constraint.
	 *
	 * @param Time The time relative to the owning movie scene where the section should be.
	 * @param ConstraintEndTime Set the constraint to end at this time.
	 * @param SocketName The socket name for the constraint.
	 * @param ConstraintId The id to the constraint.
	 */
	virtual void AddConstraint(float Time, float ConstraintEndTime, const FName SocketName, const FGuid& ConstraintId) { }

public:

	// UMovieSceneTrack interface

    virtual void RemoveAllAnimationData() override;
	virtual bool HasSection(const UMovieSceneSection& Section) const override;
	virtual void AddSection(UMovieSceneSection& Section) override;
	virtual void RemoveSection(UMovieSceneSection& Section) override;
	virtual bool IsEmpty() const override;
	virtual TRange<float> GetSectionBoundaries() const override;
	virtual const TArray<UMovieSceneSection*>& GetAllSections() const override;

#if WITH_EDITORONLY_DATA
	virtual FText GetDefaultDisplayName() const override;
#endif

protected:

	/** List of all constraint sections. */
	UPROPERTY()
	TArray<UMovieSceneSection*> ConstraintSections;
};
