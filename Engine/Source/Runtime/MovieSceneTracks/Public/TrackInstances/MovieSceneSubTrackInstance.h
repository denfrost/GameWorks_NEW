// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "IMovieSceneTrackInstance.h"


class FMovieSceneSequenceInstance;
class UMovieSceneSubSection;
class UMovieSceneSubTrack;


/**
 * Instance of a UMovieSceneSubTrack.
 */
class FMovieSceneSubTrackInstance
	: public IMovieSceneTrackInstance
{
public:

	/** Create and initialize a new instance. */
	FMovieSceneSubTrackInstance(UMovieSceneSubTrack& InTrack);

public:

	// IMovieSceneTrackInstance interface

	virtual void ClearInstance(IMovieScenePlayer& Player, FMovieSceneSequenceInstance& SequenceInstance) override;
	virtual void RefreshInstance(const TArray<UObject*>& RuntimeObjects, IMovieScenePlayer& Player, FMovieSceneSequenceInstance& SequenceInstance) override;
	virtual void RestoreState (const TArray<UObject*>& RuntimeObjects, IMovieScenePlayer& Player, FMovieSceneSequenceInstance& SequenceInstance) override;
	virtual void SaveState(const TArray<UObject*>& RuntimeObjects, IMovieScenePlayer& Player, FMovieSceneSequenceInstance& SequenceInstance) override;
	virtual void Update(EMovieSceneUpdateData& UpdateData, const TArray<UObject*>& RuntimeObjects, IMovieScenePlayer& Player, FMovieSceneSequenceInstance& SequenceInstance) override;

protected:

	TArray<UMovieSceneSection*> GetAllTraversedSectionsWithPreroll( const TArray<UMovieSceneSection*>& Sections, float CurrentTime, float PreviousTime );
	TArray<UMovieSceneSection*> GetTraversedSectionsWithPreroll( const TArray<UMovieSceneSection*>& Sections, float CurrentTime, float PreviousTime );

protected:

	/** Track that is being instanced */
	TWeakObjectPtr<UMovieSceneSubTrack> SubTrack;

	/** Mapping of section lookups to instances.  Each section has a movie scene which must be instanced */
	TMap<TWeakObjectPtr<UMovieSceneSubSection>, TSharedPtr<FMovieSceneSequenceInstance>> SequenceInstancesBySection;
};
