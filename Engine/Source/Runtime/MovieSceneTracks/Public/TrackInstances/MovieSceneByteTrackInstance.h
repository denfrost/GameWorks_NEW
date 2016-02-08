// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "IMovieSceneTrackInstance.h"


class FTrackInstancePropertyBindings;
class UMovieSceneByteTrack;


/**
 * Instance of a UMovieSceneByteTrack
 */
class FMovieSceneByteTrackInstance
	: public IMovieSceneTrackInstance
{
public:

	FMovieSceneByteTrackInstance( UMovieSceneByteTrack& InByteTrack );

	/** IMovieSceneTrackInstance interface */
	virtual void SaveState (const TArray<UObject*>& RuntimeObjects, IMovieScenePlayer& Player, FMovieSceneSequenceInstance& SequenceInstance) override;
	virtual void RestoreState (const TArray<UObject*>& RuntimeObjects, IMovieScenePlayer& Player, FMovieSceneSequenceInstance& SequenceInstance) override;
	virtual void Update(EMovieSceneUpdateData& UpdateData, const TArray<UObject*>& RuntimeObjects, IMovieScenePlayer& Player, FMovieSceneSequenceInstance& SequenceInstance) override;
	virtual void RefreshInstance( const TArray<UObject*>& RuntimeObjects, IMovieScenePlayer& Player, FMovieSceneSequenceInstance& SequenceInstance ) override;
	virtual void ClearInstance( IMovieScenePlayer& Player, FMovieSceneSequenceInstance& SequenceInstance ) override {}

private:

	/** Byte track that is being instanced */
	UMovieSceneByteTrack* ByteTrack;

	/** Runtime property bindings */
	TSharedPtr<FTrackInstancePropertyBindings> PropertyBindings;

	/** Map from object to initial state */
	TMap< TWeakObjectPtr<UObject>, uint8 > InitByteMap;
};
