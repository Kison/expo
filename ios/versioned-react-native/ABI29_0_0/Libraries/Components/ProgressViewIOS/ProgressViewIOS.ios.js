/**
 * Copyright (c) 2015-present, Facebook, Inc.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * @providesModule ProgressViewIOS
 * @flow
 */
'use strict';

const Image = require('../../Image/Image');
const NativeMethodsMixin = require('../../Renderer/shims/NativeMethodsMixin');
const React = require('react');
const PropTypes = require('prop-types');
const StyleSheet = require('../../StyleSheet/StyleSheet');
const ViewPropTypes = require('../View/ViewPropTypes');

const createReactClass = require('create-react-class');
const requireNativeComponent = require('../../ReactNative/requireNativeComponent');

/**
 * Use `ProgressViewIOS` to render a UIProgressView on iOS.
 */
const ProgressViewIOS = createReactClass({
  displayName: 'ProgressViewIOS',
  mixins: [NativeMethodsMixin],

  propTypes: {
    ...ViewPropTypes,
    /**
     * The progress bar style.
     */
    progressViewStyle: PropTypes.oneOf(['default', 'bar']),

    /**
     * The progress value (between 0 and 1).
     */
    progress: PropTypes.number,

    /**
     * The tint color of the progress bar itself.
     */
    progressTintColor: PropTypes.string,

    /**
     * The tint color of the progress bar track.
     */
    trackTintColor: PropTypes.string,

    /**
     * A stretchable image to display as the progress bar.
     */
    progressImage: Image.propTypes.source,

    /**
     * A stretchable image to display behind the progress bar.
     */
    trackImage: Image.propTypes.source,
  },

  render: function() {
    return (
      <RCTProgressView
        {...this.props}
        style={[styles.progressView, this.props.style]}
      />
    );
  }
});

const styles = StyleSheet.create({
  progressView: {
    height: 2,
  },
});

const RCTProgressView = requireNativeComponent(
  'RCTProgressView',
  ProgressViewIOS
);

module.exports = ProgressViewIOS;
