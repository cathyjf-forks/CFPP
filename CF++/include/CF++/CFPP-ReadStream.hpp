/*******************************************************************************
 * Copyright (c) 2014, Jean-David Gadina - www.xs-labs.com / www.digidna.net
 * Distributed under the Boost Software License, Version 1.0.
 * 
 * Boost Software License - Version 1.0 - August 17th, 2003
 * 
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 * 
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer,
 * must be included in all copies of the Software, in whole or in part, and
 * all derivative works of the Software, unless such copies or derivative
 * works are solely in the form of machine-executable object code generated by
 * a source language processor.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 ******************************************************************************/

/*!
 * @header      CFPP-ReadStream.h
 * @copyright   (c) 2014 - Jean-David Gadina - www.xs-labs.com / www.digidna.net
 * @abstract    CoreFoundation++ CFReadStreamRef wrapper
 */

#ifndef CFPP_READ_STREAM_H
#define CFPP_READ_STREAM_H

namespace CF
{
    class CFPP_EXPORT ReadStream: public Type
    {
        public:
            
            ReadStream( void );
            ReadStream( const std::string & path );
            ReadStream( const char * path );
            ReadStream( URL url );
            ReadStream( const ReadStream & value );
            ReadStream( const AutoPointer & value );
            ReadStream( CFTypeRef value );
            ReadStream( CFReadStreamRef value );
            
            #ifdef CFPP_HAS_CPP11
            ReadStream( ReadStream && value );
            #endif
            
            virtual ~ReadStream( void );
            
            ReadStream & operator = ( ReadStream value );
            ReadStream & operator = ( const AutoPointer & value );
            ReadStream & operator = ( CFTypeRef value );
            ReadStream & operator = ( CFReadStreamRef value );
            
            virtual CFTypeID  GetTypeID( void ) const;
            virtual CFTypeRef GetCFObject( void ) const;
            
            bool               Open( void ) const;
            bool               Open( const std::string & path );
            bool               Open( const char * path );
            bool               Open( const URL & url );
            void               Close( void ) const;
            bool               HasBytesAvailable( void ) const;
            CFStreamStatus     GetStatus( void ) const;
            Error              GetError( void ) const;
            CFIndex            Read( Data::Byte * buffer, CFIndex length ) const;
            Data               Read( CFIndex length = 0 ) const;
            const Data::Byte * GetBuffer( CFIndex maxBytesToRead, CFIndex * numBytesRead ) const;
            AutoPointer        GetProperty( const String & name );
            bool               SetProperty( const String & name, CFTypeRef value );
            bool               SetClient( CFOptionFlags events, CFReadStreamClientCallBack callback, CFStreamClientContext * context );
            void               ScheduleWithRunLoop( CFRunLoopRef runLoop, CF::String mode );
            void               UnscheduleFromRunLoop( CFRunLoopRef runLoop, CF::String mode );
            
            friend void swap( ReadStream & v1, ReadStream & v2 );
            
            #ifdef __clang__
            #pragma clang diagnostic push
            #pragma clang diagnostic ignored "-Wpadded"
            #endif
            
            class CFPP_EXPORT Iterator: public std::iterator< std::forward_iterator_tag, Data >
            {
                public:
                    
                    Iterator( void );
                    Iterator( const Iterator & value );
                    
                    #ifdef CFPP_HAS_CPP11
                    Iterator( Iterator && value );
                    #endif
                    
                    virtual ~Iterator( void );
                    
                    Iterator & operator = ( Iterator value );
                    Iterator & operator ++( void );
                    Iterator   operator ++( int );
                    
                    Iterator & operator += ( CFIndex value );
                    
                    Iterator operator + ( CFIndex value );
                    
                    bool operator == ( const Iterator & value ) const;
                    bool operator != ( const Iterator & value ) const;
                    
                    Data operator * ( void );
                    
                    operator Data ();
                    
                    friend void swap( Iterator & v1, Iterator & v2 );
                    
                private:
                    
                    friend class ReadStream;
                    
                    Iterator( CFReadStreamRef stream, CFIndex bytesToRead, bool end );
                    
                    void _Read( void );
                    
                    CFReadStreamRef _cfObject;
                    CFIndex         _bytesToRead;
                    CFIndex         _i;
                    Data            _data;
                    bool            _end;
            };
            
            #ifdef __clang__
            #pragma clang diagnostic pop
            #endif
            
            Iterator begin( CFIndex bytesToRead = 0 ) const;
            Iterator end( void ) const;
            
        private:
            
            CFReadStreamRef _cfObject;
    };
}

#endif /* CFPP_READ_STREAM_H */
