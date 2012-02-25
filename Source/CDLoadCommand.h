// -*- mode: ObjC -*-

//  This file is part of class-dump, a utility for examining the Objective-C segment of Mach-O files.
//  Copyright (C) 1997-1998, 2000-2001, 2004-2012 Steve Nygard.

#import <Foundation/Foundation.h>

// Importing these here saves us from importing them in the implementation of every load command.
#include <mach-o/loader.h>
#include "dyld-info-compat.h"
#import "CDMachOFileDataCursor.h"

@class CDMachOFile;

@interface CDLoadCommand : NSObject

+ (id)loadCommandWithDataCursor:(CDMachOFileDataCursor *)cursor;

- (id)initWithDataCursor:(CDMachOFileDataCursor *)cursor;

- (NSString *)extraDescription;

@property (readonly) CDMachOFile *machOFile;
@property (readonly) NSUInteger commandOffset;

@property (readonly) uint32_t cmd;
@property (readonly) uint32_t cmdsize;
@property (readonly) BOOL mustUnderstandToExecute;

@property (readonly) NSString *commandName;

- (void)appendToString:(NSMutableString *)resultString verbose:(BOOL)isVerbose;

- (void)machOFileDidReadLoadCommands:(CDMachOFile *)machOFile;

@end